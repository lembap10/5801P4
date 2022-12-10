#ifndef MCGENERATOR_H
#define MCGENERATOR_H

#include "JSONGenerator.h"
using namespace std;


class MCGenerator: public JSONGenerator {
    protected:
        int numChoices = 4;
    public:
        MCGenerator(Params* param) : JSONGenerator(param){

        }

        void PopulateAttributes();

        int getNumChoices(){
            return numChoices;
        }

        void setNumChoices(int choices){
            numChoices = choices;
        }

        ~MCGenerator(){

        }
};

#endif
