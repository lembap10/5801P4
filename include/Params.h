#ifndef PARAMS_H
#define PARAMS_H

#include <iostream>
#include <string>
#include <vector>

#include "ParsedCode.h"

using namespace std;

class Params {
 private:
  // numStudents - int representing the number of students for question
  // generation
  int numStudents;
  // questionType - string representing the type of question to generate
  string questionType;
  // sourceCode - ParsedCode object for problem generation
  ParsedCode* sourceCode;
  // intendedLMS - string representing the LMS to generate the json for
  string intendedLMS;
  // intendedQuizType - string representing the quiz type to generate the json
  // for
  string intendedQuizType;

 public:
  /**
   * @brief Default Constructor, initializes all attributes to default values
   *
   * @param numStudent number of students
   * @param questionType type of question
   * @param sourceCode source code
   * @param intendedLMS intended LMS
   * @param intendedQuizType intended quiz type
   */
  Params(int numStudent, string questionType, ParsedCode* sourceCode,
         string intendedLMS, string intendedQuizType);

  /**
   * @brief Default Destructor, deletes sourceCode
   *
   */
  ~Params();
  /**
   * @brief sets the number of students
   *
   * @param numStudents number of students
   */
  void setNumStudents(int numStudents);
  /**
   * @brief sets the question type
   *
   * @param questionType string to set questionType to
   */
  void setQuestionType(string questionType);
  /**
   * @brief sets the source code
   *
   * @param sourceCode ParsedCode object to set sourceCode to
   */
  void setSourceCode(ParsedCode* sourceCode);
  /**
   * @brief sets the intended LMS
   *
   * @param intendedLMS string to set intendedLMS to
   */
  void setIntendedLMS(string intendedLMS);
  /**
   * @brief sets the intended quiz type
   *
   * @param intendedQuizType string to set intendedQuizType to
   */
  void setIntendedQuizType(string intendedQuizType);
  /**
   * @brief get the number of students
   *
   * @return int value of numStudents
   */
  int getNumStudents();
  /**
   * @brief gives the question type
   *
   * @return string value of questionType
   */
  string getQuestionType();
  /**
   * @brief gives the source code
   *
   * @return ParsedCode* value of sourceCode
   */
  ParsedCode* getSourceCode();
  /**
   * @brief gives the intended LMS
   *
   * @return string value of intendedLMS
   */
  string getIntendedLMS();
  /**
   * @brief gives the intended quiz type
   *
   * @return string value of intendedQuizType
   */
  string getIntendedQuizType();
  /**
   * @brief Debugging function to print the representation of the parameters
   * prints out all information to verify the parameters
   */
  void print();
};

#endif
