#include "include/DefaultCodeParser.h"
using namespace std;

int main(){
    ParsedCode* code;
    DefaultCodeParser parser;
    code = parser.ParseCode("srcFiles/test.cpp");
    if (code == NULL){
        cout << "Error while parsing" << endl;
    }
    else {
        code->print();
    }
}