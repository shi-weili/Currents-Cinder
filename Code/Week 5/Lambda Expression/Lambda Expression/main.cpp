#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// 1A - Definition

// A lambda expression has the form
// [capture list] (parameter list) -> return type { function body }
// We can omit either or both of the parameter list and return type,
// so the minimal form of a lambda expression is
// [capture list] { function body }

auto calculateUltimateAnswer = [] { return 42; };

// Equivalent to:
// int calculateUltimateAnswer() { return 42; }


// 2B - Passing arguments to a lambda; Passing lambda as an argument.

class Country {
public:
    string name;
    int population;
};

// Define a lambda that has two parameters:

auto smaller = [] (const shared_ptr<Country> &c1, const shared_ptr<Country> &c2) {
    return c1->population <= c2->population;
};


int main(int argc, const char * argv[]) {
    
    // 1B - Definition
    int answer = calculateUltimateAnswer();
    cout << answer << endl;
    
    
    // 2A - Passing arguments to a lambda; Passing lambda as an argument.
    
    vector<int> numbers;
    for (int i = 0; i < 10; i++) {
        numbers.push_back(rand() % 100);
    }
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    
    // Introducing std::sort()
    sort(numbers.begin(), numbers.end(), less<int>());
        // less<T>() is a function template. You fill in the type you want the function to work with.
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    
    // Let's try another way of comparision:
    sort(numbers.begin(), numbers.end(), greater<int>());
    // less<T>() is a function template. You fill in the type you want the function to work with.
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;
    
    // This is sweet, but how about sorting a custom data type?
    vector<shared_ptr<Country>> countries;
    
    auto c1 = shared_ptr<Country>(new Country);
    c1->name = "United States";
    c1->population = 325629697;
    countries.push_back(c1);
    
    auto c2 = shared_ptr<Country>(new Country);
    c2->name = "China";
    c2->population = 1386103746;
    countries.push_back(c2);
    
    auto c3 = shared_ptr<Country>(new Country);
    c3->name = "Vatican";
    c3->population = 451;
    countries.push_back(c3);
    
    for (auto it = countries.begin(); it != countries.end(); it++) {
        // Wanna examine what type (*it)->name is?
//        cout << typeid(it).name() << endl;
//        cout << typeid(*it).name() << endl;
//        cout << typeid((*it)->name).name() << endl;
        cout << (*it)->name << endl;
    }
    cout << endl;
    
    sort(countries.begin(), countries.end(), smaller);
    for (auto it = countries.begin(); it != countries.end(); it++) {
        cout << (*it)->name << endl;
    }
    cout << endl;
    
    // You can also define a lambda inside a function,
    // and a lambda doesn't have to have a name.
    sort(countries.begin(), countries.end(), [] (const shared_ptr<Country> &c1, const shared_ptr<Country> &c2) {
        return c1->population >= c2->population;
    } );
    for (auto it = countries.begin(); it != countries.end(); it++) {
        cout << (*it)->name << endl;
    }
    cout << endl;
    
    
    // 3 - Captures
    // The function body of a lambda has access to local variables captured by the capture list.
    
    // Capture by value:
    auto f1 = [answer] { cout << answer << endl; }; // Answer is a local int varialbe of main() captured by the lambda.
    f1();
    
    // Note that the value of a captured variable is copied when the lambada is created, not when it is called.
    answer = 43;
    f1(); // Will output 42 instead 43!
    
    // Capture by reference:
    auto f2 = [&answer] { cout << answer << endl; };
    f2();
    answer = 42;
    f2();
    
    // If a local variable is captured by reference, the lambda can also modify it:
    auto f3 = [&answer] { answer = 0; };
    f3();
    cout << answer << endl;
    
    // Implicit captures: let the compiler inform which variables we need to capture.
    // Implicitly capture by value:
    answer = 42;
    auto f4 = [=] { cout << answer << endl; }; // Equivalent to f1
    answer = 43;
    f4();
    
    // Implicityly capture by reference:
    auto f5 = [&] { answer = 0; }; // Equivalent to f3
    f5();
    cout << answer << endl;
    
    return 0;
}
