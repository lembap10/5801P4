#include "include/DefaultCodeParser.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include "testing/tester.h"

using namespace std;

int main(){
    ParsedCode* code;
    DefaultCodeParser parser;
    string fileName;
    // Ask for a file name to be inputted
    cout << "Enter the name of the file (stored in srcFiles directory) to be parsed: ";
    cin >> fileName ;

    // Parse the file and store the parsedCode in code
    code = parser.ParseCode("srcFiles/"+fileName);
    // verify file existence
    if (code == NULL){
        cout << "Invalid file inputted" << endl;
    }
    // Print code
    else
        code->print();
    
}