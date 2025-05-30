/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:32:27 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/30 15:29:24 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <iostream>


class ScalarConverter {
private:
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