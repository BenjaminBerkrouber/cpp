/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 01:43:40 by ben               #+#    #+#             */
/*   Updated: 2024/06/04 09:16:01 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# define PURPLE "\033[35m"
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define BLACK  "\033[30m"
# define ORANGE "\033[33m"
# define RESET  "\033[0m"
# define GRAY "\033[37m"

# include <unistd.h>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cctype>
# include <string>
# include <list>
# include <queue>
# include <stack>
# include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <climits>

class BitcoinExchange
{
public:
    // Constructors
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    // Destructor
    ~BitcoinExchange();

    // Methods
    void parseFile(const std::string &filename);
    void printData() const;
    void displayWalletsValues() const;

    // Getters
    const std::map<std::string, std::string> &getMapData() const;
    const std::multimap<std::string, std::string> &getMapWallets() const;

    // Setters
    void    setMapWallets(const std::string &filename);

    void    print_line_info(const std::string& date, const std::string& btcAmount, const std::string& btcValue, const std::string& usdValue) const;

private:
    std::map<std::string, std::string> _mapData;
    std::multimap<std::string, std::string> _mapWallets;
    std::map<int, std::string> _monthNames;

    void        setMonthNames();

    void        setMapData();
    const std::string getBtcValue(const std::string &date) const;

    // check data file
    void    tryNumber(const std::string &s) const;
    
    // check date
    void    tryValidDate(const std::string &s) const;
    bool    isLeapYear(int year) const;
    void    tryValidDateFormat(const std::string &s) const;
    void    tryValidDateValues(int year, int month, int day) const;
    void    tryValidDayForMonth(int year, int month, int day) const;
    void    extractDateParts(const std::string &s, int &year, int &month, int &day) const;

    // check wallet file
    void    tryValidWalletAmount(const std::string &s) const;

};

#endif