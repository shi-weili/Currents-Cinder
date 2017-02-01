#include <iostream>

void fruitlessFunction(int a) {
    a = 0;
}

void dangerousFunction(int *a) {
    *a = 0;
}

int main(int argc, const char * argv[]) {
    int var = 100; // A normal integer
    int *ptr; // A pointer to an integer
    ptr = &var; // Assign the address of var to ptr
    std::cout << ptr << std::endl; // Print out memory address ptr points to (in hexadecimal format)
    std::cout << *ptr << std::endl; // Dereference the pointer; retrieve the value
    *ptr = 0; // Operating the variable, not the pointer
    std::cout << var << std::endl;
    std::cout << std::endl;
    
    int a = 100;
    fruitlessFunction(a);
    std::cout << a << std::endl;
    dangerousFunction(&a);
    std::cout << a << std::endl;
    std::cout << std::endl;
    
    int numbers[5];
    int *p;
    p = numbers; // The name of an array is also a pointer.
//    p = &numbers[0]; // Also works
    for (int i = 0; i < 5; i++) {
        *p = i * 10;
        p++; // Since p is a pointer to int, it will go forward with an offset same to the length of an int--pointing to the next integer in the array.
    }
    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Note that now p points to an address that is out of the array!
//    std::cout << *p << std::endl; // Undefined result!
//    *p += 1; // Danger! Operating memory you don't own!
//    std::cout << numbers[6] << std::endl; // Undefined result! C++ doesn't prevent you from doing all these dangerous things...
    
    return 0;
}
