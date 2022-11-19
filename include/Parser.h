#include "ParsedCode.h"
#include <fstream>

using namespace std;

class Parser {
    protected: 
        ifstream srcCode;
        ParsedCode codeRep;
        string filename;
    public:
        Parser() {
            codeRep = ParsedCode();
            filename = "";
        };
        virtual ParsedCode *ParseCode(string file) = 0;
};