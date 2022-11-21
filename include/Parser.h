#ifndef PARSER_H
#define PARSER_H

#include "ParsedCode.h"
#include <fstream>

using namespace std;

class Parser {
    protected: 
        // attaribute to read srcCode file
        ifstream srcCode;
        // Pointed to the filed out parsedCode object
        ParsedCode *codeRep;
        // filename which this Parser is currently used to parse
        string fileName;
    public:
        /**
         * @brief Construct a new Parser object
         * Initialize fileName to empty string
         * Initialize codeRep to NULL
         */
        Parser() {
            codeRep = NULL;
            fileName = "";
        };
        /**
         * @brief Pure virtual function to be overriden
         * allows the parser to read the source file
         * 
         * @param file name/path of file to parse
         * @return ParsedCode* pointer to the created parsed code object
         */
        virtual ParsedCode *ParseCode(string file) = 0;
        ~Parser(){
            delete codeRep;
        }
};
#endif