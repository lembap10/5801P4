#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include "Question.h"

using namespace std;

class MultipleChoiceQuestion : Question {
 protected:
  vector<string> choices;

 public:
  /**
   * @brief get the answer choices for the question
   *
   */
  void getChoices();

  /**
   * @brief set the answer choices for the question
   *
   * @param choices: vector of strings that represents the answer choices for
   * the question
   */
  void setChoices(vector<string> choices);
};

#endif