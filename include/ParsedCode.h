#ifndef PARSEDCODE_H
#define PARSEDCODE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ParsedCode{
    private:
        // numLines - int representing how many line tuples are in the represented code
        int numLines;
        // lines - vector of strings where each string is the values of one line tuple in the source code
        vector<string> lines;
        // ignored - vector of booleans which indicate if a line should not be moved
        vector<bool> ignored;
    public: 
        /**
         * @brief Default Constructor, initializes both vector attributes and numLines to 0
         * 
         */
        ParsedCode();
        /**
         * @brief Adds a tuple (string) to the lines vector
         * 
         * @param line string to add
         * @param ignore should this line be ignored
         */
        void AddCodeTuple (string line, bool ignore);
        /**
         * @brief removes a tuple from the vector lines
         * 
         * @param tupleNum tuple to remove
         */
        void RemoveCodeTuple (int tupleNum);
        /**
         * @brief gives the vector of lines
         * 
         * @return vector<string> : value of lines
         */
        vector<string> getLines();
        /**
         * @brief gives the number of tuples
         * 
         * @return int value of numLines 
         */
        int getNumTuples();
        /**
         * @brief gives the vector representing the lines to ignore
         * 
         * @return vector<bool> value of ignored
         */
        vector<bool> getIgnores();
        /**
         * @brief Debugging function to print the representation of the parsed code
         * prints out all information to verify the parsed code
         */
        void print();
        // OVERLOADED OPERATOR TO TEST EQUIVALENCE
        // for testing purposes only
        bool operator== (ParsedCode code){
            return (this->numLines == code.numLines && this->lines == code.lines && this->ignored == code.ignored);
        }
};
#endif
