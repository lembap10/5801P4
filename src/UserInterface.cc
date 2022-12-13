#include "../include/UserInterface.h"
#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string
#include <limits>
#include <cctype>
using namespace std;

/**
 * @brief Default Constructor, initializes params to nullptr
 *
 */
UserInterface::UserInterface() {
    this->params = new Params();
}

/**
 * @brief Default Destructor, deletes params
 *
 */
UserInterface::~UserInterface() { delete this->params; }

/**
 * @brief Set the attribute params
 *
 * @param params Params object to set params to
 */
void UserInterface::setParams(Params* params) { this->params = params; }

/**
 * @brief Prompts the user for the parameters for the json generation
 *
 */
void UserInterface::getInput() {
  // Initializing the variables
  int numStudents;
  string questionType;
  string intendedLMS;
  string intendedQuizType;
  DefaultCodeParser* parser = new DefaultCodeParser();
  string fileName;

  // Prompting the user for the parameters
  cout << "Type in \"quit\" to quit anytime" << endl;
  cout << "Enter the number of students: ";
  cin >> numStudents;
  // error checking
  while (cin.fail() || numStudents <= 0){
    cout << "Invalid, please enter a valid number." << endl;
    // clears failure state
    cin.clear();
    // ignores bad output 
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    cin >> numStudents;
     }

  cout << "Enter the question type (MC [Multiple Choice] or FB [Fill in the "
          "Blank]): ";
  cin >> questionType;
  while (questionType != "mc" && questionType != "fb" && questionType != "MC" &&
         questionType != "FB" && questionType != "quit") {
    cout << "Invalid question type, please enter MC or FB: ";
    // clears failure state
    cin.clear();
    // ignores bad output 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin >> questionType;
  }
  cout << "Enter the intended LMS (canvas, blackboard, or moodle): ";
  cin >> intendedLMS;
  while (intendedLMS != "canvas" && intendedLMS != "blackboard" &&
         intendedLMS != "moodle" && intendedLMS != "Canvas" &&
         intendedLMS != "Blackboard" && intendedLMS != "Moodle" &&
         intendedLMS != "quit") {
    cout << "Invalid LMS, please enter Canvas, Blackboard, or Moodle: ";
    // clears failure state
    cin.clear();
    // ignores bad output 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin >> intendedLMS;
  }
  cout << "Enter the intended quiz format (qti or gift): ";
  cin >> intendedQuizType;
  while (intendedQuizType != "qti" && intendedQuizType != "gift" &&
         intendedQuizType != "QTI" && intendedQuizType != "GIFT" &&
         intendedQuizType != "quit") {
    cout << "Invalid quiz format, please enter qti for gift: ";
    // clears failure state
    cin.clear();
    // ignores bad output 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin >> intendedQuizType;
  }
  cout << "Enter the name of the file (stored in srcFiles directory) to be "
          "parsed: ";
  cin >> fileName;
  this->params->setSourceCode(parser->ParseCode(fileName));
  while (params->getSourceCode() == NULL && fileName != "quit") {
    cout << "Invalid file name, please enter a valid file name: ";
    // clears failure state
    cin.clear();
    // ignores bad output 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin >> fileName;
    this->params->setSourceCode(parser->ParseCode(fileName));
  }

  // Creating the params object
  // Params* temp = new Params(numStudents, questionType, sourceCode, intendedLMS,
  //                           intendedQuizType);
  // temp->print();
  //   this->setParams(temp);

  params->setNumStudents(numStudents);
  params->setQuestionType(questionType);
  params->setIntendedLMS(intendedLMS);
  params->setIntendedQuizType(intendedQuizType);
}

/**
 * @brief return the params object
 *
 */
Params* UserInterface::getParams() { 
  return this->params; 
}