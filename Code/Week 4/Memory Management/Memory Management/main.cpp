#include <iostream>

// 7A: Introducing iterators:
#include <vector>


// 8A: Dynamic memory
#include <cstdlib>
#include <list>


using namespace std;

// 2A: Pointers to objects

class Country {
public:
    int population;
};


// 3A: Pointers in functions

// By default, functions get there arguments by value:
void add1(int input) {
    input += 1;
}

// By using pointers as parameters, functions get access to arguments thenselves:
void add1(int *input) {
    *input += 1;
}


// 5A: References in functions

// By using reference as parameters, functions get access to arguments thenselves:
void add100(int &input) { // can't define add1(int &) because of conflict with add1(int).
    input += 1;
}



int main(int argc, const char * argv[]) {
    
    // 1: Pointers revisited
    
    int int1 = 0;
    int int2 = 100;
    int *intPtr; // definition of a pointer to int
    intPtr = &int1; // assign intPtr the address of int1
    cout << intPtr << endl;
    cout << *intPtr << endl;
    
    *intPtr = 50; // assign int1 through intPtr
    cout << int1 << endl;
    
    intPtr = &int2; // ressign intPtr the address of int2
    cout << intPtr << endl;
    cout << *intPtr << endl;
    
    
    // 2B: Pointers to objects
    
    Country usa;
    usa.population = 325584692;
    Country *countryPtr = &usa; // definition of a pointer to Country
    cout << countryPtr->population << endl; // accessing members of the object using "->"
    
    
    // 3B: Pointers in function
    int int3 = 1;
    add1(int3); // call by value
    cout << int3 << endl;
    
    add1(&int3); // call by pointer
    cout << int3 << endl;
    // But still, calling a funtion by pointer requires efforts on the user side (using "&" to get address).
    
    
    // 4: Introducing reference
    int int4 = 0;
    int &intRef = int4; // definition of reference; needs to intilize it at the same time.
    intRef = 101; // A reference is like an alias of the object it refers to. You access the object without using the dereference operator "*".
    cout << int4 << endl;
    
    
    // 5A: References in functions
    add100(int4); // call by reference; no difference from calling by value.
    cout << int4 << endl;
    
    
    // 6: Using pointers to access array elements:
    
    // Remember how we use a pointer to access the elements of an array one by one?
    int intArray[10];
    for (int i = 0; i < 10; i++) {
        intArray[i] = i * 100;
    }
    int *intPtr2 = intArray; // definition of a pointer to int; assign it the address of the first element of intArray.
    for (int i = 0; i < 10; i++) {
        cout << *intPtr2 << endl;
        intPtr2++; // advance to the next memory address
    }
    // For those container classes provided by C++ standard library, you can use iterators to go through all the elements in a similiar way.
    
    
    // 7B: Introducing iterators:
    vector<int> intVector; // definition of a vector ("smart array") of int.
    for (int i = 0; i < 10; i++) {
        intVector.push_back(i * 1000); // append new elements to the back of the vector; the vector will grow in capacity if necessary.
    }
    // Using iterators to go through all elements:
    for (vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++) {
        // intVector.begin() returns an iterator pointing to the first element.
        // You can also write: auto it = intVector.begin();
        // intVector.end() returns the address after the last element.
        // if it == intVector.end(), it is pointing out of the vector.
        // it++ advances it to the next element, just like pointer math.
        
        cout << *it << endl; // *it is the element it points to, just like pointer dereferencing.
    }
    
    
    // 8B: Dynamic memory
    // Imagine we have a "world" of Countries stored in a list. As time passes by, new Countries are born and old Countries dissappear. How do we simulate this in code?
    
    // Version 1: store values
//    list<Country> world; // a list of Country (like a vector, but easy to operate in both ends).
//    while(true) { // infinite loop
//        if(rand() % 100 >= 50) { // 50% chance to add a new Country
//            Country newCountry;
//            newCountry.population = rand();
//            world.push_back(newCountry); // Append the new Country to the list.
//        }
//        
//        if(world.size() > 0 && rand() % 100 >=50) { // If list is not empty, 50% chance to remove the oldest Country.
//            world.pop_front(); // Remove the first element from the list.
//        }
//        
//        cout << "Country count: " << world.size() << endl;
//    }
    // Storing values (the Country objects themselves) has at least 2 problems:
    // 1. We are not storing the Country objects we created in the while loop; instead, we stored copies of them! When we push the object to the back of the list, the list automatically makes a copy of the object and store it, and discards the original object. In many cases, this is not the behavior we want.
    // 2. The copy operation takes time, which can affect the performance, especially when we deal with a big amount of objects.
    
    // Version 2: store pointers
//    list<Country *> world; // a list of pointers to Country
//    while(true) { // infinite loop
//        if(rand() % 100 >= 50) { // 50% chance to add a new Country
//            Country* newCountryPtr = new Country(); // "New" operator allocates memory dynamically, and returns the address of the new object.
//            newCountryPtr->population = rand();
//            world.push_back(newCountryPtr); // Append the address of the new Country to the list.
//        }
//        
//        if(world.size() > 0 && rand() % 100 >=50) { // If list is not empty, 50% chance to delete the oldest Country.
//            delete world.front(); // "Delete" operator accepts a memory address (pointer), and frees up the memory it points to. Profile the program without this line to demostrate memory leak.
//            world.pop_front(); // And this step is to remove the pointer from the list.
//        }
//        
//        cout << "Country count: " << world.size() << endl;
//    }
    // Allocating and deallocating dymanic memory is one of the most error-prone parts of C++ programming. In this case, it is easy to decide where to delete the dymaically created object. But in many cases, things are more complicated, and if you forget to free up the allocated memory, your program will gradually drain all the available memory of your computer, and make it really slow, or crash.
    
    // Version 3: store shared pointers
    list<shared_ptr<Country>> world; // a list of shared pointers to Country
    while(true) { // infinite loop
        if(rand() % 100 >= 50) { // 50% chance to add a new Country
            shared_ptr<Country> newCountryPtr(new Country()); // Construct a shared_ptr with a newly constructed dynamic object
            newCountryPtr->population = rand();
            world.push_back(newCountryPtr); // Append the shared_ptr to the new Country to the list.
        }
        
        if(world.size() > 0 && rand() % 100 >=50) { // If list is not empty, 50% chance to delete the oldest Country.
            // No need to delete the dynamic object manually! The shared_ptr will manage the memory autamically. It will count the number of references to the object it points to. Once the number drops to 0, it will delete the object. Therefore, when we remove the share_ptr itself from the list in the next line, the number of reference drops to 0, and the shared_ptr will delete the object it points to.
            world.pop_front(); // And this step is to remove the pointer from the list.
        }
        
        cout << "Country count: " << world.size() << endl;
    }
    
    return 0;
}
