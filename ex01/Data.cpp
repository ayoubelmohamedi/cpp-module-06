

#include "Data.hpp"


Data::Data(const std::string &name, int n) : _name(name), _n(n) {}

Data::Data(const Data &other)
{
    *this = other;
}

Data &Data::operator=(const Data & other)
{
    if (this != &other)
    {
        this->_n = other._n;
        this->_name = other._name;
    }
    return (*this);
}

Data::~Data()
{

}

const std::string& Data::getName() const
{
    return (_name);
};

int Data::getNumber() const 
{
    return (_n);
};

void Data::setNumber(int nbr)
{
    this->_n = nbr;
}
void Data::setName(std::string &name)
{
    this->_name = name;
}

std::ostream &operator<<(std::ostream &os, const Data &data) {
    os << "Data(name: " << data.getName() << ", n: " << data.getNumber() << ")";
    return os;
}