/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:32:27 by ael-moha          #+#    #+#             */
/*   Updated: 2025/06/01 20:48:37 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cfloat> 
#include <cerrno>

class ScalarConverter {
private:
    ScalarConverter();
    static bool is_char(const std::string & literal);
    static bool is_int(const std::string &literal);
    static bool is_float(const std::string & literal);
    static bool is_double(const std::string &literal);
    static bool is_float_ps(const std::string &literal);
    static bool is_double_ps(const std::string &literal);

    static void to_double(const std::string &literal);
    static void to_float(const std::string &literal);
    static void to_char(const std::string &literal);
    static void to_int(const std::string &literal);

    static bool is_nan(double d);
    static bool is_inf(double d);
    static bool is_nanf(float f);
    static bool is_inff(float f);
    
    
    
public:
    static void convert(const std::string& literal);
    
};



#endif