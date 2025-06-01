

#include "ScalarConverter.hpp"


bool ScalarConverter::is_char(const std::string & literal)
{
    if (literal.length() == 1 && isalpha(literal[0]))
        return (true);
    return (false);
}

bool ScalarConverter::is_float(const std::string & literal)
{
    float val = std::atof(literal.c_str());
    if (isnan(val) || isinf(val))
        return (is_float_ps(literal));
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

bool ScalarConverter::is_int(const std::string &literal)
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

bool ScalarConverter::is_float_ps(const std::string &literal)
{
    return (literal == "nanf" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::is_double(const std::string &literal)
{
    if (literal.empty())
        return (false);
    if (literal.find('.') == std::string::npos)
        return (false);
    char *end;
    errno = 0;
    double d = std::strtod(literal.c_str(), &end);
    if (*end != 0 || errno == ERANGE)
        return (false); 
    if (isnan(d) || isinf(d))
        return (is_double_ps(literal));
    return (true);
}

bool ScalarConverter::is_double_ps(const std::string &literal)
{
    return (literal == "nan" || literal == "+inf" || literal == "-inf");
}

bool ScalarConverter::is_nan(double d)
{
    return (d != d);
}
bool ScalarConverter::is_inf(double d)
{
    return (!is_nan(d) && (d + d == d));
}
bool ScalarConverter::is_nanf(float f)
{
    return (f != f);
}
bool ScalarConverter::is_inff(float f)
{
    return (!is_nanf(f) && (f + f == f));
}