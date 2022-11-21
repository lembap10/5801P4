#ifndef DEFAULTCODEPARSER_H
#define DEFAULTCODEPARSER_H

#include "Parser.h"

using namespace std;

class DefaultCodeParser : Parser {
    public: 
        ParsedCode* ParseCode(string file);
};
#endif
