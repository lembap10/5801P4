#include "../include/Params.h"
using namespace std;

/**
 * @brief Construct a new Params:: Params object
 *
 * @param numStudent
 * @param questionType
 * @param sourceCode
 * @param intendedLMS
 * @param intendedQuizType
 */
Params::Params(int numStudent, string questionType, ParsedCode* sourceCode,
               string intendedLMS, string intendedQuizType) {
  this->numStudents = numStudent;
  this->questionType = questionType;
  this->sourceCode = sourceCode;
  this->intendedLMS = intendedLMS;
  this->intendedQuizType = intendedQuizType;
}

/**
 * @brief Destroy the Params:: Params object
 *
 */
Params::~Params() { /**delete sourceCode;**/ }

/**
 * @brief sets the number of students
 *
 * @param numStudents number of students
 */
void Params::setNumStudents(int numStudents) {
  this->numStudents = numStudents;
}

/**
 * @brief sets the question type
 *
 * @param questionType string to set questionType to
 */
void Params::setQuestionType(string questionType) {
  this->questionType = questionType;
}

/**
 * @brief sets the source code
 *
 * @param sourceCode ParsedCode object to set sourceCode to
 */
void Params::setSourceCode(ParsedCode* sourceCode) {
  this->sourceCode = sourceCode;
}

/**
 * @brief sets the intended LMS
 *
 * @param intendedLMS string to set intendedLMS to
 */
void Params::setIntendedLMS(string intendedLMS) {
  this->intendedLMS = intendedLMS;
}

/**
 * @brief sets the intended quiz type
 *
 * @param intendedQuizType string to set intendedQuizType to
 */
void Params::setIntendedQuizType(string intendedQuizType) {
  this->intendedQuizType = intendedQuizType;
}

/**
 * @brief get the number of students
 *
 * @return int value of numStudents
 */
int Params::getNumStudents() { return numStudents; }

/**
 * @brief gives the question type
 *
 * @return string value of questionType
 */
string Params::getQuestionType() { return questionType; }

/**
 * @brief gives the source code
 *
 * @return ParsedCode* value of sourceCode
 */
ParsedCode* Params::getSourceCode() { return sourceCode; }

/**
 * @brief gives the intended LMS
 *
 * @return string value of intendedLMS
 */
string Params::getIntendedLMS() { return intendedLMS; }

/**
 * @brief gives the intended quiz type
 *
 * @return string value of intendedQuizType
 */
string Params::getIntendedQuizType() { return intendedQuizType; }

/**
 * @brief prints the parameters
 *
 */
void Params::print() {
  cout << "Number of students: " << numStudents << endl;
  cout << "Question type: " << questionType << endl;
  cout << "Source code: ";
  sourceCode->print();
  cout << endl;
  cout << "Intended LMS: " << intendedLMS << endl;
  cout << "Intended quiz type: " << intendedQuizType << endl;
}