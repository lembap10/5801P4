#include "Parser.h"

using namespace std;

class DefaultCodeParser : Parser {
    public: 
        ParsedCode* ParseCode(string file);
};