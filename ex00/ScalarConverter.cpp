/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:31:28 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/30 16:38:23 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"


/*
    parms: string literal => belongs to one of these scalars {char, int, float, double}
    Except for 'char', only decimal notation will be used 
    if char is non displayable =  Non displayable
    
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

/*
    /convert 0
    char: Non displayable
    int: 0
    float: 0.0f
    double: 0.0 
*/

void to_char(const std::string &literal)
{
    char c = static_cast<char>(literal[0]);
   
    if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: "  <<  static_cast<char>(c) << std::endl; 
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void to_int (const std::string &literal)
{
    int d = static_cast<int>(std::atoi(literal.c_str()));

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: "  <<  static_cast<char>(d) << std::endl; 

    std::cout << "int: " << d << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{ 
    if (is_char(literal))
    {
        to_char(literal);
    }
    else if (is_int(literal))
    {

    }
    else if (is_float(literal))
    {

    }
    else if (is_double(literal))
    {
        
    }
    else if (is_float_ps(literal))
    {
        
    }
    else if (is_double_ps(literal))
    {
        
    }
    else 
    {
        // error ? 
    std::cout << "========Not charrr===========" << std::endl;
    char c = literal[0];
    std::cout << "char: "  <<  static_cast<char>(c) << std::endl; 
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        
    }
    
}
