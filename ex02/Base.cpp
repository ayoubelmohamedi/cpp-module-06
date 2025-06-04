


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0)));
    int n = std::rand() % 3;

    if (n == 0)
        return (new A());
    if (n == 1)
            return (new B());
    return (new C());
}


void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}
}