/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:31:28 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/30 15:25:31 by macbookpro       ###   ########.fr       */
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




void ScalarConverter::convert(const std::string &literal)
{ 
    // if (is_char(literal))
    // {
        
    // }
    // else if (is_int(literal))
    // {

    // }
    // else if (is_float(literal))
    // {

    // }
    // else if (is_double(literal))
    // {
        
    // }
    // else if (is_float_ps(literal))
    // {
        
    // }
    // else if (is_double_ps(literal))
    // {
        
    // }
    std::cout << "is double " << is_double(literal) << std::endl;
    
}
