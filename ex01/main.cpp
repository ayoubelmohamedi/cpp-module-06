

#include "Serializer.hpp"



int main() {
    
    Data data("Sam", 5);
    uintptr_t ptr =  Serializer::serialize(&data);
    std::cout << ptr << std::endl;
    std::cout << Serializer::deserialize(ptr) << std::endl;
    std::cout << *Serializer::deserialize(ptr) << std::endl;
}
