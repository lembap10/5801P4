#ifndef MCGENERATOR_H
#define MCGENERATOR_H

#include "JSONGenerator.h"
using namespace std;


class MCGenerator: public JSONGenerator {
    protected:
        int numChoices = 4;
    public:
    /**
   * @brief constructor for multiple choice JSON generator
   *@param param
   *@param numChoices
   */
        MCGenerator(Params* param, int numChoices) : JSONGenerator(param){
            this->setNumChoices(numChoices);
        }

 /**
   * @brief populates specific multiple choice attributes like
   * number of choices to generator
   *
   */
        void PopulateAttributes();

 /**
   * @brief get the number of choices
   * @return int
   *
   */
        int getNumChoices(){
            return numChoices;
        }

    /**
   * @brief set the number of choices
   * @param choices
   */

        void setNumChoices(int choices){
            numChoices = choices;
        }

    /**
   * @brief destructor
   */

        ~MCGenerator(){

        }
};

#endif
