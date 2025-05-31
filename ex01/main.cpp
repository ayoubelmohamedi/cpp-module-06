


#include <iostream>
#include <iomanip>



int main() {
    int i = 1065353216; // This is the bit pattern of float 1.0f
    float f = reinterpret_cast<float&>(i);

    std::cout << "Int: " << sizeof(int) << "\n";
    std::cout << "Float: " << sizeof(float) << "\n";  // Output: 1.0
}
