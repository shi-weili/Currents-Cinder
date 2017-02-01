// Using <> to include file makes the preprocessor start search from system paths,
// while using "" makes it start from project path:
#include <iostream>
#include "answer.h"
#include "include/question.h" // Can also add "include" to project path.

// Comment out the std lines, and preprocess the code.

#define PI 3.1415926 // #define only replaces the defined name with value. It doesn't do type checking.
const double E = 2.7182818285; // Recommended way to define constants.

#define MULT(x, y) x * y // Macros can be used similiarly as functions, but with many caveats.
int mult(int x, int y) { return x * y; } // Using function instead is much safer.

// Macros are type-neutral, which is handy to use. But function templates can be also be as convenient (but safer).
template <typename T>
T add(T x, T y) {
    return x + y;
}

int main(int argc, const char * argv[]) {
    std::cout << theAnswer << std::endl;
    std::cout << theRealAnswer << std::endl;
    
    std::cout << 2 * PI << std::endl;
    std::cout << E << std::endl;
    
    std::cout << MULT(1 + 2, 3 + 4) << std::endl;
    std::cout << mult(1 + 2, 3 + 4) << std::endl;
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
//    std::cout << add(1, 2.2) << std::endl; // Will fail to build
    std::cout << add((double)1, 2.2) << std::endl; // Cast the first parameter to double
    
    return 0;
}
