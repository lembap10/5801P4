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
    fileName = file;

    // Verify file type is allowed
    string fileType = fileName.substr(fileName.find(".") + 1, fileName.length());
    if (fileType != "cpp" || fileType != "c" || fileType != "cc" || fileType != "cs" || fileType != "h" || fileType != "java" || fileType != "py" || fileType != "js" ){
        cout << "Error: Invalid file type" << endl;
        return NULL;
    }

    string commentSymbol = "";

    // Find the needed commentSymbol for this file type
    if (fileType == "cpp" || fileType == "c" || fileType == "cc" || fileType == "cs" || fileType == "h" || fileType == "java"|| fileType == "js" ){
        commentSymbol = "//";
    }
    else if (fileType == "py"){
        commentSymbol = "#";
    }

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