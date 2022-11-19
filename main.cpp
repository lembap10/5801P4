#include "include/DefaultCodeParser.h"
using namespace std;

int main(){
    ParsedCode code;
    DefaultCodeParser parser;
    parser.ParseCode("srcFiles/test.cpp");
}