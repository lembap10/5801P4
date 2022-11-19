#include "ParsedCode.h"
#include <fstream>

using namespace std;

class Parser {
    private: 
        ifstream srcCode;
        ParsedCode codeRep;
        string filename;
    public:
        Parser();
        virtual ParseCode(string filename) = 0;
};