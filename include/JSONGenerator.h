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
        JSONGenerator(Params* param);

        // pure 
        void PopulateAttributes(){
            
        }

        // returns filename of new JSON file
        string createJSONFile();

        ~JSONGenerator(){

        };
};

#endif
