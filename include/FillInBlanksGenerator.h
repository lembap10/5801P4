#ifndef FILLINBLANKSGENERATOR_H
#define FILLINBLANKSGENERATOR_H

#include "JSONGenerator.h"
using namespace std;


class FillInBlanksGenerator: public JSONGenerator {
    protected:
        int blankLength;
    public:
        FillInBlanksGenerator(Params* param) : JSONGenerator(param){

        }

        void PopulateAttributes();

        int getBlankLength(){
            return blankLength;
        }

        void setBlankLength(int length){
            blankLength = length;
        }

        ~FillInBlanksGenerator(){

        }
};

#endif
