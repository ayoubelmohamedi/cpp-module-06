/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:31:28 by ael-moha          #+#    #+#             */
/*   Updated: 2025/06/04 19:38:28by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <climits>

ScalarConverter::ScalarConverter(){};

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
};

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
};

ScalarConverter::~ScalarConverter(){};

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    double value;

    if (literal == "nan" || literal == "+nan" || literal == "-nan") {
        value = std::numeric_limits<double>::quiet_NaN();
    } else if (literal == "nanf" || literal == "+nanf" || literal == "-nanf") {
        value = std::numeric_limits<double>::quiet_NaN();
    } else if (literal == "inf" || literal == "+inf") {
        value = std::numeric_limits<double>::infinity();
    } else if (literal == "-inf") {
        value = -std::numeric_limits<double>::infinity();
    } else if (literal == "inff" || literal == "+inff") {
        value = std::numeric_limits<double>::infinity();
    } else if (literal == "-inff") {
        value = -std::numeric_limits<double>::infinity();
    } else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    } else {
        std::string to_parse = literal;
        if (to_parse.length() > 1 && to_parse[to_parse.length() - 1] == 'f' && to_parse.find('.') != std::string::npos && (to_parse.find('.') == to_parse.rfind('.')) ) {
            to_parse = to_parse.substr(0, to_parse.length() - 1);
        }
        char *end;
        errno = 0;
        float f = std::strtof(to_parse.c_str(), &end);
        if (*end != '\0' || errno == ERANGE) {
            std::cout << "Error: Invalid input" << std::endl;
            return;
        }
        value = static_cast<double>(f);
    }

    // Char output
    if (value < CHAR_MIN || value > CHAR_MAX || (value != value))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // Int output
    if (value < INT_MIN || value > INT_MAX || (value != value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // Float output
    float f = static_cast<float>(value);
    if (f != f)
        std::cout << "float: nanf" << std::endl;
    else if (std::numeric_limits<float>::infinity() == f)
        std::cout << "float: inff" << std::endl;
    else if (-std::numeric_limits<float>::infinity() == f)
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // Double output
    if (value != value)
        std::cout << "double: nan" << std::endl;
    else if (std::numeric_limits<double>::infinity() == value)
        std::cout << "double: inf" << std::endl;
    else if (-std::numeric_limits<double>::infinity() == value)
        std::cout << "double: -inf" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}