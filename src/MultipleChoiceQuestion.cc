#include "../include/MultipleChoiceQuestion.h"
using namespace std;

/**
 * @brief get the answer choices for the question
 *
 */
vector<string> getChoices() { return choices; }

/**
 * @brief set the answer choices for the question
 *
 * @param choices: vector of strings that represents the answer choices for the
 * question
 */
void setChoices(vector<string> choices) { this->choices = choices; }
