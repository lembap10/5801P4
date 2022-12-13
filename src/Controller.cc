#include "../include/Controller.h"
#include <limits>
#include <typeinfo>
using namespace std;

void Controller::CreateFile(){
  int input;
  this->ui->getInput();

  // obtain user parameters
  Params* params;
  params = this->ui->getParams(); 
  JSONGenerator* gen = nullptr;

  // add additional parameters specified for multiple choice and fill in blank
  if (params->getQuestionType() == "MC"){
     cout << "How many choices(Multiple Choice Options)" << endl;
     cin >> input;

     // error checking
     while (cin.fail() || input <= 0){
        cout << "Invalid, please enter a valid number." << endl;
        // clears failure state
        cin.clear();
        // ignores bad output 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cin >> input;
     }
     
     gen = new MCGenerator (params, input);
  }
  else{
     cout << "Length of Blank (Fill in Blank)" << endl;
     cin >> input;
     
     // error checking
     while (cin.fail() || input <= 0){
        cout << "Invalid, please enter a valid number." << endl;
        // clears failure state
        cin.clear();
        // ignores bad output 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        cin >> input;
     }
     gen = new FillInBlanksGenerator (params, input);
  }
  
  // add additional attributes to generation
  gen->PopulateAttributes();

  // create file
  string jsonFile = gen->createJSONFile();
  cout << "succesfully created file " << jsonFile << endl;
  // delete
  delete gen;
  delete this->ui;

}

