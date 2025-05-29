/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 01:33:41 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/29 22:11:20 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {

    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]);
    } 
    else
        std::cout << "Usage: ./convert <literal>\n";
    return 0;
}