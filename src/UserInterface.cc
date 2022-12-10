#include "../include/UserInterface.h"

#include <cctype>
using namespace std;

/**
 * @brief Default Constructor, initializes params to nullptr
 *
 */
UserInterface::UserInterface() {
  //   ParsedCode* code;
  //   this->params = new Params(0, "", code, "", "");
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
  ParsedCode* sourceCode;
  DefaultCodeParser parser;
  string fileName;

  // Prompting the user for the parameters
  cout << "Type in \"quit\" to quit anytime" << endl;
  cout << "Enter the number of students: ";
  cin >> numStudents;
  cout << "Enter the question type (MC [Multiple Choice] or FB [Fill in the "
          "Blank]): ";
  cin >> questionType;
  while (questionType != "mc" && questionType != "fb" && questionType != "MC" &&
         questionType != "FB" && questionType != "quit") {
    cout << "Invalid question type, please enter MC or FB: ";
    cin >> questionType;
  }
  cout << "Enter the intended LMS (canvas, blackboard, or moodle): ";
  cin >> intendedLMS;
  while (intendedLMS != "canvas" && intendedLMS != "blackboard" &&
         intendedLMS != "moodle" && intendedLMS != "Canvas" &&
         intendedLMS != "Blackboard" && intendedLMS != "Moodle" &&
         intendedLMS != "quit") {
    cout << "Invalid LMS, please enter Canvas, Blackboard, or Moodle: ";
    cin >> intendedLMS;
  }
  cout << "Enter the intended quiz format (qti or gift): ";
  cin >> intendedQuizType;
  while (intendedQuizType != "qti" && intendedQuizType != "gift" &&
         intendedQuizType != "QTI" && intendedQuizType != "GIFT" &&
         intendedQuizType != "quit") {
    cout << "Invalid quiz format, please enter qti for gift: ";
    cin >> intendedQuizType;
  }
  cout << "Enter the name of the file (stored in srcFiles directory) to be "
          "parsed: ";
  cin >> fileName;
  sourceCode = parser.ParseCode(fileName);
  while (sourceCode == NULL && fileName != "quit") {
    cout << "Invalid file name, please enter a valid file name: ";
    cin >> fileName;
    sourceCode = parser.ParseCode(fileName);
  }

  // Creating the params object
  Params* temp = new Params(numStudents, questionType, sourceCode, intendedLMS,
                            intendedQuizType);
  temp->print();
  //   this->params = (Params*)temp;
  //   this->setParams(temp);
  //   this->params->setNumStudents(temp->getNumStudents());
  //   this->params->setQuestionType(temp->getQuestionType());
  //   this->params->setSourceCode(temp->getSourceCode());
  //   this->params->setIntendedLMS(temp->getIntendedLMS());
  //   this->params->setIntendedQuizType(temp->getIntendedQuizType());
}

/**
 * @brief return the params object
 *
 */
Params* UserInterface::getParams() { return this->params; }