#include <iostream>
#include <string>
using namespace std;

int main(){
    char c = -120;
    cout << static_cast<int>(c) << "\n"; //this is how you change em i recommend this
    int d = (signed char) c;
    cout << d; //This also works
} 