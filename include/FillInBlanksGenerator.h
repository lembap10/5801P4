#ifndef FILLINBLANKSGENERATOR_H
#define FILLINBLANKSGENERATOR_H

#include "JSONGenerator.h"
using namespace std;


class FillInBlanksGenerator: public JSONGenerator {
    protected:
        int blankLength;
    public:
     /**
   * @brief constructor for fill in blanks json generator
   *
   */
        FillInBlanksGenerator(Params* param, int blankLength) : JSONGenerator(param){
            this->setBlankLength(blankLength);
        }

 /**
   * @brief populates additional attributes such as blankLength
   *
   */
        void PopulateAttributes();

 /**
   * @brief getter for length
   * @return blankLength
   *
   */
        int getBlankLength(){
            return blankLength;
        }
 /**
   * @brief setter for length
   * @param length
   *
   */

        void setBlankLength(int length){
            this->blankLength = length;
        }

        ~FillInBlanksGenerator(){

        }
};

#endif
