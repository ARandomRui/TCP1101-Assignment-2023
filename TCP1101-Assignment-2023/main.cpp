#include <iostream>
#include <string>
#include <functional>  
#include <map> //to map strigns to functions
#include <fstream> //to read files
#include <iomanip>
#include <cctype>
using namespace std;

bool isInteger(const string& str){       //Checks if the string is an integer
   if (str.empty()) {
       return false; //Shouldn't happen
   }
   for (char c : str) {
       if (!isdigit(c)) {
           return false;
       }
   }
   return true;
}

void IN(string x, char regist[], char memory[]) { //just a showcase what you can do
    string temp;
    bool correct = 0;
    while (!correct){
        cout << "Input a number between -127 to 127 here:" << endl;
        cin >> temp;
        if (temp.empty()){
            cout << "Invalid. Please try again" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        } else{
            try{
                int tempint = stoi(temp);
                if (tempint > 127 || tempint < -127){
                    cout << "Invalid. Please enter a number between -127 and 127" << endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                    continue;
                } else {
                    correct = 1;
                }
            } catch (const exception &err){
                cout << "Invalid. Please enter a number" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                continue;
            }
        } 
    }
    int tempint = stoi(temp);
    if (isalpha(x[0]) && x[0] == 'R'){
        int index = x[1] - '0';
        regist[index] = tempint; //make sure your variable is always an integer when putting it into memory/register
    } else {
      int index = stoi(x);
      memory[index] = tempint;
    }
}
/*
void OUT(string x, char regist[], char memory[]) {
  // Add your logic here
}

void MOV(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void ADD(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void SUB(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void MUL(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void DIV(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void INC(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void DEC(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void ROL(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void ROR(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void SHL(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void LOAD(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}

void STORE(string x, string y, char regist[], char memory[]) {
  // Add your logic here
}*/

int main(){
    char memory[64] = {};
    char regist[7] = {};
    char flags[4] = {}; //Carry , Over Flow, Under flow, Zero Flag
    int PC = 0; //since the assingment didn't mention its a single byte 
    map<string, function<void(string,char[], char[])>> funcMap1 = {  //Uncomment the function you are doing on
        { "IN", IN}/*
        { "OUT", OUT }*/
        };
    map<string, function<void(string,string,char[], char[])>> funcMap2 = {  //Uncomment the function you are doing on
        /*{"MOV", MOV},
        {"ADD", ADD},
        {"SUB", SUB},
        {"MUL", MUL},
        {"DIV", DIV},
        {"INC", INC},
        {"DEC", DEC},
        {"ROL", ROL},
        {"ROR", ROR},
        {"SHL", SHL},
        {"LOAD", LOAD},
        {"STORE", STORE}    */
        };
    //Example for IN 43 
    //if ADD 24 R5 put "IN", "43" , "R5" Respectively
    string input = "IN"; //Change here to test out if your code works
    string inputx = "43"; 
    string inputy = ""; //to here
    funcMap1[input](inputx,regist, memory); //Uncomment the kind you are working on since IN and OUT only takes 1 parameter
    //funcMap2[input](inputx,inputy,regist,memory); 
    //Start data printing
    cout << "Registers: ";
    for (char x: regist){
        cout << setw(2) << setfill('0') << static_cast<int>(x) << " "; //required to print out integers, yea you must print it out as integers
    }
    cout << "#" << endl;
    cout << "Flags: ";
    for (char x: flags){
        cout << setw(2) << setfill('0')<< static_cast<int>(x) << " ";
    }
    cout << "#" << endl << "PC: " << PC << endl << endl;
    int rowcount = 0;
    cout << "Memory:" << endl;
    for (char x: memory){
        if (rowcount >= 8){
            cout << endl;
            rowcount = 0;
        }
        cout  << setw(2) << setfill('0')<< static_cast<int>(x) << " "; //required to print out integers, yea you must print it out as integers    
        rowcount++;
    }
    cout << endl <<"#" << endl;
    //End data printing
}





