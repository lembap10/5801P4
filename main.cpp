#include <iostream>  // std::cout
#include <sstream>   // std::stringstream
#include <string>    // std::string

#include "include/DefaultCodeParser.h"
#include "include/UserInterface.h"
#include "testing/tester.h"
#include "include/FillInBlanksGenerator.h"
#include "include/MCGenerator.h"
#include "include/Controller.h"
using namespace std;

int main() {
  // call controller and exit
  // one time program
  Controller controller;
  controller.CreateFile();
  return 0;
}