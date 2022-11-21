#ifndef DEFAULTCODEPARSER_H
#define DEFAULTCODEPARSER_H

#include "Parser.h"

using namespace std;

class DefaultCodeParser : Parser {
    public: 
        /**
         * @brief Function to create a ParsedCode Object from a source-code file
         * 
         * @param file a string representing the file name of the code to parse
         * @return ParsedCode* the populated ParsedCode object made from the file
         */
        ParsedCode* ParseCode(string file);
};
#endif
