/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 01:37:53 by ben               #+#    #+#             */
/*   Updated: 2024/06/06 13:36:52 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ========== Constructors ==========

ScalarConverter::ScalarConverter(void) {

}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
    (void)rhs; 
    return *this;
}

// ========== Destructor ==========

ScalarConverter::~ScalarConverter(void) {

}

// ========== Public methods ==========

void ScalarConverter::convert(const std::string &input) {
    char *end;

    if (input == "-inf" || input == "+inf" || input == "nan") {
        double d = std::strtod(input.c_str(), NULL);
        displayDouble(d);
        return;
    }

    if (input == "-inff" || input == "+inff" || input == "nanf") {
        float f = std::strtof(input.c_str(), NULL);
        displayFloat(f);
        return;
    }

    double d = std::strtod(input.c_str(), &end);
    if (*end == '\0') {
        displayDouble(d);
        return;
    }

    float f = std::strtof(input.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0') {
        displayFloat(f);
        return;
    }

    long l = std::strtol(input.c_str(), &end, 10);
    if (*end == '\0' && l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max()) {
        displayInt(static_cast<int>(l));
        return;
    }

    if (input.length() == 1 && !std::isdigit(input[0])) {
        char c = input[0];
        displayChar(c);
        return;
    }

    std::cout << RED << "  Invalid input" << RESET << std::endl;
}

void ScalarConverter::displayChar(char c) {
    std::cout << "  char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "  int: " << static_cast<int>(c) << std::endl;
    std::cout << "  float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "  double: " << static_cast<double>(c) << std::endl << std::endl;
}

void ScalarConverter::displayInt(int n) {
    std::cout << "  char: ";
    if (n >= std::numeric_limits<char>::min() && n <= std::numeric_limits<char>::max() && isprint(n))
        std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "  int: " << n << std::endl;
    std::cout << "  float: " << static_cast<float>(n) << "f" << std::endl;
    std::cout << "  double: " << static_cast<double>(n) << std::endl << std::endl;
}

void ScalarConverter::displayFloat(float f) {
    std::cout << "  char: ";
    if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max() && isprint(static_cast<int>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "  int: ";
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() && !std::isnan(f) && !std::isinf(f))
        std::cout << static_cast<int>(f) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "  float: " << f << "f" << std::endl;
    std::cout << "  double: " << static_cast<double>(f) << std::endl << std::endl;
}

void ScalarConverter::displayDouble(double d) {
    std::cout << "  char: ";
    if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max() && isprint(static_cast<int>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "  int: ";
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() && !std::isnan(d) && !std::isinf(d))
        std::cout << static_cast<int>(d) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    
    std::cout << "  float: ";
    if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max() && !std::isnan(d) && !std::isinf(d))
        std::cout << static_cast<float>(d) << "f" << std::endl;
    else if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "  double: " << d << std::endl << std::endl;
}
