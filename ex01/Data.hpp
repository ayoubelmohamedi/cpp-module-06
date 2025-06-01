/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:05:08 by ael-moha          #+#    #+#             */
/*   Updated: 2025/05/31 21:47:10 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>


class Data
{
    private: 
        std::string _name;
        int _n;
    
    public:
        Data(const std::string& name, int n);
        Data(const Data & other);
        Data &operator=(const Data & other);
        ~Data();

        const std::string& getName() const;
        int getNumber() const;

        void setNumber(int nbr);
        void setName(std::string &name);
};


std::ostream &operator<<(std::ostream & os, const Data & data);