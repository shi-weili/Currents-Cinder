//
//  main.cpp
//  ScopesAndNamespaces
//
//  Created by Weili Shi on 2017/1/24.
//  Copyright © 2017年 Weili Shi. All rights reserved.
//

#include <iostream>

// scopes:

int foo;        // global variable

void function1 ()
{
    int bar;      // local variable
    bar = 0;
}

void function2 ()
{
    foo = 1;  // ok: foo is a global variable
    bar = 2;  // wrong: bar is not visible from this function
}

void function3 ()
{
    int x;
    x = 0;
    double x;   // wrong: name already used in this scope
    x = 0.0;
}

// inner block scopes:

void function4 () {
        int x = 10;
    int y = 20;
    {   // a pair of curly braces makes a scope
        int x;   // ok, inner scope. makes the outer space x invisible
        x = 50;  // sets value to inner x
        y = 50;  // sets value to (outer) y
        std::cout << "inner block:\n";
        std::cout << "x: " << x << '\n';
        std::cout << "y: " << y << '\n';
    }
    std::cout << "outer block:\n";
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

// namespaces:

namespace space1
{
    int value() { return 5; }
}

namespace space2
{
    const double pi = 3.1416;
}

namespace space2 {
    double value() { return 2*pi; }
}

namespace s2 = space2; // namespace aliasing

void function5 () {
    using namespace std; // the using directive
    cout << space1::value() << '\n';
    cout << space2::pi << '\n';
    cout << s2::value() << '\n';
}

int main(int argc, const char * argv[]) {
    function4();
    function5();
    return 0;
}
