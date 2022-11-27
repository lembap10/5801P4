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

    cout << "Parsing code..." << endl;

    // Parse the file and store the parsedCode in code
    code = parser.ParseCode("srcFiles/"+fileName);

    // verify file existence
    if (code == NULL){
        cout << "Invalid file inputted" << endl;
    }

    char yorn;
    cout << "Do you want to print the parsed code representation? (y/n): ";
    cin >> yorn;
    if (yorn == 'y' or == 'Y'){
        code->print();
    }
    else {
        cout << "Code representation stored in variable code. " << endl;
    }
    return 0; 
}