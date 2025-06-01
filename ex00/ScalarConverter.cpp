/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:31:28 by ael-moha          #+#    #+#             */
/*   Updated: 2025/06/01 23:49:41 by ael-moha         ###   ########.fr       */
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

    if (literal.length() == 1 && !std::isdigit(literal[0]))
        value = static_cast<double>(literal[0]);
    else
    {
        char *end;
        errno = 0;
        float f = std::strtof(literal.c_str(), &end);
        if (*end != '\0' || errno == ERANGE)
        {
            std::cout << "Error: Invalid input" << std::endl;
            return;
        }
        std::cout << " is float " << std::endl;
        value = static_cast<double>(f);
    }

    if (value < CHAR_MIN || value > CHAR_MAX || std::isnan(value))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value < INT_MIN || value > INT_MAX || std::isnan(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(value) << "f" << std::endl;

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << value << std::endl;
}