/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:58:11 by ben               #+#    #+#             */
/*   Updated: 2024/06/04 09:31:26 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// ================== CONSTRUCTORS ================== //

BitcoinExchange::BitcoinExchange() {
    try {
        setMapData();
        setMonthNames();
    } catch (const std::exception &e) {
        _mapData.clear();
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_mapData = other._mapData;
    }
    return *this;
}


// ================== DESTRUCTOR ================== //

BitcoinExchange::~BitcoinExchange() {
}

// ================== METHODS ================== //


std::string reformatValue(const std::string &value) {
    std::string result;

    if (value == "N/A")
        return ("N/A");
    else if (value == "You are so rich mean!")
        return ("You are so rich mean!");
    size_t len = value.length();
    len = value.find('.');
    if (len == std::string::npos)
        len = value.length();
    // else
    //     len = len;

    if (value.find('.') != std::string::npos) {
        for (size_t i = value.find('.') + 1; i < value.length(); i++) {
            result.push_back(value[i]);
        }
        result.push_back('.');
    }
    for (int i = len - 1; i >= 0; --i) {
        result.push_back(value[i]);
        if ((len - i) % 3 == 0 && i != 0) {
            result.push_back(',');
        }
    }


    std::reverse(result.begin(), result.end());
    return result;
}

std::string cal(const std::string &str1, const std::string &str2) {
    if (str2 == "N/A")
        return "N/A";
    long long num1 = std::atoll(str1.c_str());
    long long num2 = std::atoll(str2.c_str());

    if (num1 != 0 && num2 != 0)
        if (num1 > LLONG_MAX / num2 || num1 < LLONG_MIN / num2)
            return "You are so rich mean!";

    long long result = num1 * num2;
    std::ostringstream oss;
    oss << result;
    return oss.str();
}

void BitcoinExchange::print_line_info(const std::string& date, const std::string& btcAmount, const std::string& btcValue, const std::string& usdValue) const {
    std::cout << "│ " << std::setw(15) << std::right << date << " │ "
            << std::setw(15) << std::right << btcAmount << " │ "
            << std::setw(25) << std::right << btcValue << " │ "
            << std::setw(30) << std::right << usdValue << " │" << std::endl;
}

void BitcoinExchange::displayWalletsValues() const {
    std::cout << "Wallets values:" << std::endl;
    bool findError = false;

    std::cout << "╒═════════════════╤═════════════════╤═══════════════════════════╤════════════════════════════════╕" << std::endl;
    print_line_info("Date", "BTC quantity", "BTC value", "Value wallet in USD");

    for (std::multimap<std::string, std::string>::const_iterator it = _mapWallets.begin(); it != _mapWallets.end(); ++it) {
        std::string date = it->first;
        if (date == "Error") {
            if (!findError)
                std::cout << "╞═════════════════╧═════════════════╧═══════════════════════════╧════════════════════════════════╡" << std::endl;
            else
                std::cout << "╞════════════════════════════════════════════════════════════════════════════════════════════════╡" << std::endl;
            findError = true;
            std::cout << "│ " << RED << std::setw(95) << std::left << it->second << RESET << "│" << std::endl;
            continue;
        }
        std::cout << "╞═════════════════╪═════════════════╪═══════════════════════════╪════════════════════════════════╡" << std::endl;
        std::string value = it->second;
        std::string btcValue = getBtcValue(date);
        print_line_info(date, reformatValue(value), reformatValue(btcValue), reformatValue(cal(value, btcValue)));
    }
    if (!findError)
        std::cout << "╘═════════════════╧═════════════════╧═══════════════════════════╧════════════════════════════════╛" << std::endl;
    else
        std::cout << "╘════════════════════════════════════════════════════════════════════════════════════════════════╛" << std::endl;
}

// ================== UTILS ================== //

// --------- Checkers --------- //

void    BitcoinExchange::tryNumber(const std::string &s) const {
    bool hasDecimal = false;
    bool hasDigit = false;

    if (s.empty())
        throw std::runtime_error("Empty value in wallet amount");

    if (s[0] == '-')
        throw std::runtime_error("Negative value in wallet amount");

    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            hasDigit = true;
        } else if (s[i] == '.') {
            if (!hasDecimal) {
                hasDecimal = true;
            } else {
                throw std::runtime_error("Invalid character in wallet amount");
            }
        } else {
            throw std::runtime_error("Invalid character in wallet amount");
        }
    }
    if (!hasDigit)
        throw std::runtime_error("No digit in wallet amount");
}


void BitcoinExchange::tryValidDateFormat(const std::string &s) const {
    if (s.length() < 10) {
        throw std::runtime_error("No possible date format");
    }
    for (size_t i = 0; i < s.length(); i++) {
        if (i == 4 || i == 7) {
            if (s[i] != '-')
                throw std::runtime_error("Bad separator in date format");
        }
        else {
            if (!isdigit(s[i]))
                throw std::runtime_error("Invalide character in date format");
        }
    }
}

void BitcoinExchange::extractDateParts(const std::string &s, int &year, int &month, int &day) const {
    char dash1, dash2;
    std::stringstream ss(s);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (dash1 != '-' || dash2 != '-') {
        throw std::runtime_error("Bad separator in date format");
    }
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void BitcoinExchange::tryValidDayForMonth(int year, int month, int day) const {
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29)
                throw std::runtime_error("In Bissextile year, Max February days is 29");
        } else {
            if (day > 28)
                throw std::runtime_error("In no Bissextile year, Max February days is 28");
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            std::string monthName = _monthNames.at(month);
            std::ostringstream oss;
            oss << "Max days in " << monthName << " is 30";
            throw std::runtime_error(oss.str());
        }
    }
}

void BitcoinExchange::tryValidDateValues(int year, int month, int day) const {
    if (year < 0)
        throw std::runtime_error("Year is negative");
    if (month < 1 || month > 12)
        throw std::runtime_error("Month is not in range [1, 12]");
    if (day < 1 || day > 31)
        throw std::runtime_error("Day is not in range [1, 31]");
}

void    BitcoinExchange::tryValidDate(const std::string &s) const {
    int year, month, day;

    tryValidDateFormat(s);
    extractDateParts(s, year, month, day);
    tryValidDateValues(year, month, day);
    tryValidDayForMonth(year, month, day);
}

void BitcoinExchange::tryValidWalletAmount(const std::string &s) const {
    bool hasDecimal = false;
    bool hasDigit = false;

    if (s.empty())
        throw std::runtime_error("Empty value in wallet amount");

    if (s[0] == '-')
        throw std::runtime_error("Negative value in wallet amount");

    for (size_t i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            hasDigit = true;
        } else if (s[i] == '.') {
            if (!hasDecimal) {
                hasDecimal = true;
            } else {
                throw std::runtime_error("Invalid character in wallet amount");
            }
        } else {
            throw std::runtime_error("Invalid character in wallet amount");
        }
    }
    if (!hasDigit)
        throw std::runtime_error("No digit in wallet amount");
    float amount = atof(s.c_str());
    if (amount > 1000)
        throw std::runtime_error("Amount is too high");
}

// ================== GETTERS ================== //

const std::map<std::string, std::string> &BitcoinExchange::getMapData() const {
    return (_mapData);
}

const std::multimap<std::string, std::string> &BitcoinExchange::getMapWallets() const {
    return (_mapWallets);
}

const std::string BitcoinExchange::getBtcValue(const std::string &date) const {
    if (_mapData.empty()) {
        return ("N/A");
    }
    
    std::string last_data = _mapData.rbegin()->first;
    if (date > last_data) {
        return ("N/A");
    }
    std::map<std::string, std::string>::const_iterator it = _mapData.find(date);
    if (it == _mapData.end()) {
        std::map<std::string, std::string>::const_iterator it2 = _mapData.lower_bound(date);
        if (it2 == _mapData.begin()) {
            return ("N/A");
        }
        it2--;
        return (it2->second);
    }

    return (it->second);
}

// ================== SETTERS ================== //

void    BitcoinExchange::setMonthNames() {
    _monthNames[1] = "January";
    _monthNames[2] = "February";
    _monthNames[3] = "March";
    _monthNames[4] = "April";
    _monthNames[5] = "May";
    _monthNames[6] = "June";
    _monthNames[7] = "July";
    _monthNames[8] = "August";
    _monthNames[9] = "September";
    _monthNames[10] = "October";
    _monthNames[11] = "November";
    _monthNames[12] = "December";
}

void BitcoinExchange::setMapData() {
    int line_index = 1;
    std::ifstream file("data.csv");

    if (!file.is_open()) {
        std::cerr << RED << "Error: could not open DATA file" << RESET << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        line_index++;
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            std::ostringstream oss;
            oss << "    [" << line_index << "] {" + line + "} => FORMAT ERROR (none \",\" find)";
            std::string error = oss.str();
            std::cerr << RED << error << RESET << std::endl;
            continue;
        }
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);

        try {
            tryValidDate(key);
        } catch (const std::exception &e) {
            std::ostringstream oss;
            oss << "    [" << line_index << "] {" + line + "} => FORMAT ERROR (" << e.what() << ")";
            std::string error = oss.str();
            std::cerr << RED << error << RESET << std::endl;
            continue;
        }

        try {
            tryNumber(value);
        } catch (const std::exception &e) {
            std::ostringstream oss;
            oss << "    [" << line_index << "] {" + line + "} => FORMAT ERROR (" << e.what() << ")";
            std::string error = oss.str();
            std::cerr << RED << error << RESET << std::endl;
            continue;
        }
        _mapData[key] = value;
    }
    file.close();
}


void BitcoinExchange::setMapWallets(const std::string &filename) {
    std::ifstream file;
    std::string line;
    int line_index = 0;

    file.open(filename.c_str());

    if (!file.is_open()) {
        std::cerr << RED << "Error: could not open wallets file [" << filename << "]" << RESET << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        line_index++;
        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::ostringstream oss;
            oss << "[" << line_index << "] {" + line + "} => FORMAT ERROR (none \"|\" find)";
            std::string error = oss.str();
            _mapWallets.insert(std::make_pair("Error", error));
            continue;
        }
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        if (key.empty() || key[key.size() - 1] != ' ') {
            std::ostringstream oss;
            oss << "[" << line_index << "] {" + line + "} => FORMAT ERROR (not have space after key)";
            std::string error = oss.str();
            _mapWallets.insert(std::make_pair("Error", error));
            continue;
        }

        if (value.empty()) {
            std::ostringstream oss;
            oss << "[" << line_index << "] {" + line + "} => FORMAT ERROR (value is empty)";
            std::string error = oss.str();
            _mapWallets.insert(std::make_pair("Error", error));
            continue;
        }

        if (value[0] != ' ') {
            std::ostringstream oss;
            oss << "[" << line_index << "] {" + line + "} => FORMAT ERROR (value is empty)";
            std::string error = oss.str();
            _mapWallets.insert(std::make_pair("Error", error));
            continue;
        }
        key.erase(key.size() - 1);
        value.erase(0, 1);

        try {
            tryValidDate(key);
        } catch (const std::exception &e) {
            std::ostringstream oss;
            oss << "[" << line_index << "] {" + line + "} => FORMAT ERROR (" << e.what() << ")";
            std::string error = oss.str();
            _mapWallets.insert(std::make_pair("Error", error));
            continue;
        }

        try {
            tryValidWalletAmount(value);
        } catch (const std::exception &e) {
            std::ostringstream oss;
            oss << "[" << line_index << "] {" + line + "} => FORMAT ERROR (" << e.what() << ")";
            std::string error = oss.str();
            _mapWallets.insert(std::make_pair("Error", error));
            continue;
        }

        _mapWallets.insert(std::make_pair(key, value));
    }
    file.close();
}
