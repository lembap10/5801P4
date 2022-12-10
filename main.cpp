#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string

#include "include/DefaultCodeParser.h"
#include "include/UserInterface.h"
#include "testing/tester.h"
#include "include/FillInBlanksGenerator.h"
#include "include/MCGenerator.h"
using namespace std;

int main() {
  // ParsedCode* code;
  // DefaultCodeParser parser;
  // string fileName;
  // // Ask for a file name to be inputted
  // cout << "Enter the name of the file (stored in srcFiles directory) to be "
  //         "parsed: ";
  // cin >> fileName;

  // cout << "Parsing code..." << endl;

  // // Parse the file and store the parsedCode in code
  // code = parser.ParseCode(fileName);

  // // verify file existence
  // if (code == NULL) {
  //   cout << "Invalid file inputted" << endl;
  //   // return 1;
  // }

  // char yorn;
  // cout << "Do you want to print the parsed code representation? (y/n): ";
  // cin >> yorn;
  // if (yorn == 'y' or yorn == 'Y') {
  //   code->print();
  // } else {
  //   cout << "Code representation stored in variable code. " << endl;
  // }

  UserInterface ui;
  ui.getInput();
  Params* params = ui.getParams();
  
  JSONGenerator* gen = new MCGenerator (params);
 
  gen->PopulateAttributes();

  string jsonFile = gen->createJSONFile();
  
  cout << "succesfully created file " << jsonFile << endl;
  

  return 0;
}