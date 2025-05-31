/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:32:27 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/31 18:12:53 by ael-moha         ###   ########.fr       */
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
#include <cfloat> 

class ScalarConverter {
private:
    ScalarConverter();
    static bool is_char(const std::string & literal);
    static bool is_int(const std::string &literal);
    static bool is_float(const std::string & literal);
    static bool is_double(const std::string &literal);
    static bool is_float_ps(const std::string &literal);
    static bool is_double_ps(const std::string &literal);
    
public:
    static void convert(const std::string& literal);
    
};



#endif