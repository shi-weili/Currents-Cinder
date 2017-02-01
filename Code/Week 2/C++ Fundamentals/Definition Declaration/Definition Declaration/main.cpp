#include <iostream>
#include "externalVariable.h"

// Defining something means providing all of the necessary information to create that thing in its entirety.

// Defining a function means providing a function body:
int add1(int a) {
    return a + 1;
}

// Defining a class means giving all of the methods of the class and the fields:
class Dog {
public:
    void bark() {
        std::cout << "Stop that." << std::endl;
    }
};

// Defining a variable means you are telling the compiler where to create the storage for that variable:
int score;

// A declaration provides basic attributes of a symbol: its type and its name.
// Once something is defined, that also counts as declaring it.

// The use of extern is creating a declaration of a variable but NOT defining it; it is saying that the storage for the variable is somewhere else.
extern float euro2Usd;

// For definition without initialization: variables with static storage duration are implicitly initialized with NULL (all bytes have the value 0); the initial value of all other variables is undefined. Rule of thumb: initialize variables by yourself!
int x[100];

int main(int argc, const char * argv[]) {
    
    std::cout << add1(100) << std::endl;
    
    Dog don;
    don.bark();
    
    score = 100; // Assignment
    
    float valueInEuro = 100;
    std::cout << valueInEuro * euro2Usd << std::endl; // Without definition of euro2Usd, the code compiles but fails to link.

    for (int i = 0; i < 100; i++) {
        std::cout << "x [" << i << "] = " << x[i] << std::endl;
    }
    
    int y[100];
    for (int i = 0; i < 100; i++) {
        std::cout << "y [" << i << "] = " << y[i] << std::endl;
    }
    
}
