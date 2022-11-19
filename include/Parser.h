#include "ParsedCode.h"
#include <fstream>

using namespace std;

class Parser {
    protected: 
        ifstream srcCode;
        ParsedCode codeRep;
        string fileName;
    public:
        Parser() {
            codeRep = ParsedCode();
            fileName = "";
        };
        virtual ParsedCode *ParseCode(string file) = 0;
};