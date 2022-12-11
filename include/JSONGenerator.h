#ifndef JSONGENERATOR_H
#define JSONGENERATOR_H
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
#include "Params.h"
#include "UserInterface.h"

class JSONGenerator{
    protected:
        vector<vector<string>> jsonAttributes;
    public:
     /**
   * @brief constructor for JSON generator
   *
   */
        JSONGenerator(Params* param);
 /**
   * @brief abstract virtual method meant to be overridden
   * by inherited classes; deals with additional question specific
   * attributes
   * 
   *
   */
        // pure 
        virtual void PopulateAttributes() = 0;

 /**
   * @brief creates a JSON file
   * @return file name
   *
   */
        // returns filename of new JSON file
        string createJSONFile();

 /**
   * @brief destructor
   *
   */
        ~JSONGenerator(){

        };
};

#endif
