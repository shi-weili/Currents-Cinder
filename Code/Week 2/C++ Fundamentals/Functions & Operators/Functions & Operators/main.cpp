#include <iostream>

// Function definition:
int operate(int a) {
    return a + 1;
}

// Overloading:
double operate(double a) {
    return a + 0.1;
}

// Overloading depends on parameter list, not return type:
//float operate(double a) {
//    return a + 0.2;
//}

// Default values for parameters:
int divide(int a, int b = 2) {
    return a / b;
}

// Default values can only defined for parameters to the end of the list:
//int divide(int a, int b = 2, int c) {
//    return a / b / c;
//}

// If you seperate function declaration and definition, don't redefine default values:
int mult(int a, int b = 2);

//int mult(int a, int b = 2) {
//    return a * b;
//}

// Recursivity:
unsigned int fibonacci (unsigned int a) {
    if (a == 0) { // end condition to avoid infinite recursive loop
        return 0;
    } else if (a == 1) {
        return 1;
    } else {
        return fibonacci(a - 1) + fibonacci(a - 2); // recursive call to itself
    }
}

// Operator overloading for user defined types:
class Integer {
public:
    Integer(int value) {
        this->value = value;
    }
    int value;
};

Integer operator+(Integer a, Integer b) {
    return Integer(a.value + b.value);
}

int main(int argc, const char * argv[]) {
    std::cout << operate(10) << std::endl;
    std::cout << operate(10.0) << std::endl;
    std::cout << divide(10) << std::endl;
    std::cout << divide(10, 5) << std::endl;
    std::cout << std::endl;
    
    for (int i = 1; i <= 10; i++) {
        std::cout << fibonacci(i) << std::endl;
    }
    std::cout << std::endl;
    
    Integer integer1(100), integer2(200);
    Integer integer3 = integer1 + integer2;
    
    // Compound assignment operators:
    int a = 0, b = 0, c = 0;
    a += 1; // equivalent to a = a + 1
    std::cout << a << std::endl; // FYI: << is also an operator overloaded by C++ Standard Library for I/O usage
    std::cout << b++ << std::endl;
    std::cout << b << std::endl;
    std::cout << ++c << std::endl;
    std::cout << c << std::endl;
    std::cout << std::endl;
    
    // Modulo operator:
    for (int i = 0; i < 10; i++) {
        std::cout << i % 3 << std::endl;
    }
    std::cout << std::endl;
    
    // Conditional ternary operator:
    int x = 1, y = 2;
    std::cout << (x > y ? x : y) << std::endl; // Best practice: use parentheses to resolve operator precedence issues when uncertain.
    std::cout << std::endl;
    
    // Relational and comparison operators:
    std::cout << std::boolalpha << (7 == 5) << std::endl;     // evaluates to false. Also: boolean values and numbers can be implicitly casted back-and-forth.
    std::cout << (5 > 4) << std::endl;      // evaluates to true
    std::cout << (3 != 2) << std::endl;     // evaluates to true
    std::cout << (6 >= 6) << std::endl;     // evaluates to true
    std::cout << (5 < 5) << std::endl;      // evaluates to false
    std::cout << std::endl;
    
    // Logical operators:
    std::cout << !(5 > 4) << std::endl;      // evaluates to false
    std::cout << ((5 > 4) && (1 > 2)) << std::endl; // evaluates to false.
    std::cout << ((5 > 4) || /* never executed here */ (1 > 2)) << std::endl; // evaluates to true.
    std::cout << ((3 > 4) && /* never executed here */ (1 > 2)) << std::endl; // evaluates to false.
    std::cout << (5 < 4 || 2 > 1 && 3 > 2) << std::endl; // evaluates to true. && has higher precedence than ||
    
    return 0;
}
