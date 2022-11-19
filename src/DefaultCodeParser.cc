#include "../include/DefaultCodeParser.h"

using namespace std;

/**
 * @brief 
 * 
 * @param file 
 * @return ParsedCode 
 */
ParsedCode* DefaultCodeParser::ParseCode(string file){
    ParsedCode* returnedCode = new ParsedCode();

    // Open and verify file is open
    srcCode.open(file);
    if (!srcCode.is_open()){
        return NULL;
    }

    // Iterate through file
    string curLine;
    string curTuple;
    int i = 0;

    while(getline(srcCode, curLine)){
        cout << "line: " << i << " is " <<  curLine << endl;
        i++;
    }

    // Close srcCode file
    srcCode.close();

    return returnedCode;
}