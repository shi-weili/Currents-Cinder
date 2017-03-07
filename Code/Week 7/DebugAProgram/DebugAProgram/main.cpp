#include <iostream>
using namespace std;

class Country {
public:
    Country() {
//        cout << "Country::Country() called!" << endl;
        mName = "Utopia";
        mPopulation = 42;
    }
    Country(int population) /* : Country() */ {
//        cout << "Country::Country(int population) called!" << endl;
        mPopulation = population;
    }
    string mName;
    int mPopulation;
};

int main(int argc, const char * argv[]) {
    Country country1 = Country();
    cout << "country1.mName: " << country1.mName << endl;
    cout << "country1.mPopulation: " << country1.mPopulation << endl;
    
    Country country2 = Country(100);
    cout << "country2.mName: " << country2.mName << endl;
    cout << "country2.mPopulation: " << country2.mPopulation << endl;
    
//    Country *countryPtr;
////    countryPtr = new Country();
////    cout << "countryPtr is pointing to " << countryPtr << endl;
//    countryPtr->mName = "Dystopia";
//    cout << "countryPtr->mName: " << countryPtr-> mName << endl;
////    delete countryPtr;
////    countryPtr = nullptr;
    
    return 0;
}
