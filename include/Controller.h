#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string

#include "DefaultCodeParser.h"
#include "UserInterface.h"
#include "../testing/tester.h"
#include "FillInBlanksGenerator.h"
#include "MCGenerator.h"

using namespace std;

class Controller {
 protected:
 UserInterface* ui;

 public:
  /**
   * @brief constructor for controller
   *
   */
    Controller(){
        this->ui = new UserInterface();
    }

   /**
   * @brief create user's desired file
   *
   */

    void CreateFile();

};
#endif