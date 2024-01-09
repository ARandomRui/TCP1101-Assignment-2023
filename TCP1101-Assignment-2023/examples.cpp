#include <iostream>
#include <string>
using namespace std;

int main(){
    // WAYS TO MAKE CHARACTER INTO INTEGER
    char c = 127; //from -127 to 127 
    cout << static_cast<int>(c) << "\n"; //recommended

    int d = (signed char) c;
    cout << d; 
    
    // WAY TO PRINT ARRAYS
    char array[49] = {};
    for (char x: array){
        cout << static_cast<int>(x) << "\n"; //static_casr is required to print out integers
    }
}   