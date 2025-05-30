/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:31:28 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/30 14:05:16 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"


/*
    parms: string literal => belongs to one of these scalars {char, int, float, double}
    Except for 'char', only decimal notation will be used 
    if char is non displayable = 
    
    1 - casting between scalars, we use static_cast
    2- determine type: + if (len == 1 and not digit) : return char
                    + if (is_special_float_double ==  -inff, +inff
                                    and nanf. "nan", "inf", "+inf", 
                                "-inf", "nanf", "nanf", "inff", etc) : return float or double ? 
                    + if  (has_float_notation == 'f') return (float )
                    + if (only degit , may have + or - ) return int 
                    + if (has . or exponent e/E and is valid) return double

    Errors:
    1 - If a conversion to char is not displayable, prints an informative message.
        such as : "Non displayable"
    2 - If a conversion does not make any sense or overflows, display a message to inform
        the user that the type conversion is impossible. 
*/

bool is_char(const std::string & literal)
{
    if (literal.length() == 1 && isalpha(literal[0]))
        return (true);
    return (false);
}

bool is_float(const std::string & literal)
{
    size_t len = literal.length();
    size_t f_pos = literal.find_first_of("fF");
    if (f_pos == std::string::npos || f_pos != len - 1 || literal.find_first_of("fF", f_pos + 1) != std::string::npos)
        return (false);
    
    std::string nbrPart = literal.substr(0, len - 1);
    char *end;
    errno = 0;
    std::strtof(nbrPart.c_str(), &end);
    if (*end != 0 || errno == ERANGE)
        return (false);

    return (true);    
}

bool is_int(const std::string &literal)
{
    long nbr;
    char *end;
    size_t i = 0;
    if (literal.empty())
        return (false);
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i == literal.length())
        return (false);
    for (; i < literal.length();  ++i)
    {
        if (!isdigit(literal[i]))
            return (false);
    }
    nbr = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE || nbr < INT_MIN || nbr > INT_MAX)
        return false;
    return (true);
}

bool is_float_ps(const std::string &literal)
{
    return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool is_double_ps(const std::string &literal)
{
    return (literal == "nan" || literal == "+inf" || literal == "-inf");
}


void ScalarConverter::convert(const std::string &literal)
{
    std::cout << "is float " << is_float(literal) << std::endl;
    
}
