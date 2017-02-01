#include <iostream>
#include <iomanip>
#include <limits> // std::numeric_limits

int main(int argc, const char * argv[]) {
    
    std::cout << "Size of char : " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of short int : " << sizeof(short int) << " bytes" <<  std::endl;
    std::cout << "Size of unsigned int : " << sizeof(unsigned int) << " bytes" <<  std::endl;
    std::cout << "Size of int : " << sizeof(int) << " bytes" <<  std::endl;
    std::cout << "Size of long int : " << sizeof(long int) << " bytes" <<  std::endl;
    std::cout << "Size of float : " << sizeof(float) << " bytes" <<  std::endl;
    std::cout << "Size of double : " << sizeof(double) << " bytes" <<  std::endl;
    std::cout << std::endl;
    
    std::cout << "Minimum value for char: " << (int)std::numeric_limits<char>::min() << std::endl;
    std::cout << "Maximum value for char: " << (int)std::numeric_limits<char>::max() << std::endl;
    std::cout << "Minimum value for short int: " << std::numeric_limits<short int>::min() << std::endl;
    std::cout << "Maximum value for short int: " << std::numeric_limits<short int>::max() << std::endl;
    std::cout << "Minimum value for unsigned int: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << "Maximum value for unsigned int: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Minimum value for int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Minimum value for long int: " << std::numeric_limits<long int>::min() << std::endl;
    std::cout << "Maximum value for long int: " << std::numeric_limits<long int>::max() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Number of digits for float: " << std::numeric_limits<float>::digits10 << std::endl; // the number of base-10 digits that can be represented without losing precision
    std::cout << "Maximum exponent for float: " << std::numeric_limits<float>::max_exponent10 << std::endl; // maximum power of 10 (not of mathematical constant e) that can be represented
    std::cout << "Maximum value for float: " << std::setprecision(std::numeric_limits<float>::digits10) << std::numeric_limits<float>::max() << std::endl;
    std::cout << "Number of digits for double: " << std::numeric_limits<double>::digits10 << std::endl;
    std::cout << "Maximum exponent for double: " << std::numeric_limits<double>::max_exponent10 << std::endl;
    std::cout << "Maximum value for double: " << std::setprecision(std::numeric_limits<double>::digits10) << std::numeric_limits<double>::max() << std::endl;
    std::cout << std::endl;
    
    // Be careful when dealing with edge cases:
    short int shorty = 32767;
    shorty++;
    std::cout << "(short int)32767 + 1 = " << shorty << std::endl; // problematic
    
    // Especially with unsigned types:
    unsigned int z = 0;
    z--;
    std::cout << "(unsigned int)0 - 1 = " << z << std::endl; // problematic
    
    // Type casting:
    double d = 10.3;
    int i;
    i = d; // implicit casting
    i = int(d); // functional notation
    i = (int)d; // c-like cast notation
    
    // Without correct data type, you lose precision:
    int a = 3;
    std::cout << "half of " << a << " equals " << a / 2 << std::endl; // problematic
    std::cout << "half of " << a << " equals " << a / 2.0 << std::endl;
    std::cout << "half of " << a << " equals " << (double)a / 2 << std::endl;
    
    // Enumerated types:
    enum Color {
        Red,
        Green,
        Blue
    };
    Color aColor = Blue; // Note that enumerator names are in the same scope as the enum! Polluting global namespace!
    std::cout << "aColor is " << aColor << std::endl; // An enum is actually a number!
    
    // Best practice is to use C++ 11's enum class:
    enum class Animal {
        Dog,
        Deer,
        Cat,
        Bird,
        Human
    };
    Animal anAnimal = Animal::Dog; // Enumerator names are local to the enum
//    std::cout << "anAnimal is " << anAnimal << std::endl; // Values do not implicitly convert to numbers
    
    return 0;
}
