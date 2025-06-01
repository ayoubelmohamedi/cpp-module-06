


#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>


int main ()
{
    float a=  'inf';
    double res = static_cast<double>(a);
    const char* inff_str = "inf";
    // std::cout << std::strtof(inff_str, NULL) << std::endl;
    // std::cout << std::strtod(inff_str, NULL) << std::endl;
    std::cout << res << std::endl;


    return (0);
}