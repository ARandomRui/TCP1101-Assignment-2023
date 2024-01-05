#include <iostream>
#include <string>
using namespace std;

int main(){
    char array[49] = {}; 
    for (char &x: array){
        x = 99; 
    } //required to use &x to point to the element of the real array
    //so what actually happens here is char x:array areates a copy of every element, but &x brings us to the real one
    for (char x: array){
        cout << x << "\n";
    }
} 


