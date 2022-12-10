#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <string>
#include <vector>

#include "DefaultCodeParser.h"
#include "Params.h"
#include "ParsedCode.h"

using namespace std;

class UserInterface {
 private:
  // Params - Params object that holds the parameters for the json generation
  Params* params;

 public:
  /**
   * @brief Default Constructor, initializes params to nullptr
   *
   */
  UserInterface();
  /**
   * @brief Default Destructor, deletes params
   *
   */
  ~UserInterface();
  /**
   * @brief Prompts the user for the parameters for the json generation
   *
   */
  void getInput();

  /**
   * @brief Set the attribute params
   *
   * @param params Params object to set params to
   */
  void setParams(Params* params);
  /**
   * @brief return the parameters for the json generation
   *
   * @return Params* : value of params
   */
  Params* getParams();
};
#endif
