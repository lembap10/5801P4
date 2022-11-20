#include "../include/DefaultCodeParser.h"

using namespace std;

const string START_STARTBLOCK = "{START";
const string START_TUPLE = "{*";
const string START_ENDBLOCK = "{END";
const string END_STARTBLOCK = "START}";
const string END_TUPLE = "*}";
const string END_ENDBLOCK = "END}";

/**
 * @brief Parses code for annotation in (format in annotation.md)
 * 
 * @param file 
 * @return *ParsedCode representation of the file, or NULL on error
 */
ParsedCode* DefaultCodeParser::ParseCode(string file){

    // FOR DEBUGGING PURPOSE
    bool debug = false;

    // INITIALIZE
    ParsedCode* returnedCode = new ParsedCode();
    fileName = file;

    // Verify file type is allowed
    string fileType = fileName.substr(fileName.find(".") + 1, fileName.length());
    if (fileType != "cpp" && fileType != "c" && fileType != "cc" && fileType != "cs" && fileType != "h" && fileType != "java" && fileType != "py" && fileType != "js" ){
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
    bool inTuple = false;
    bool ignore = false;
    while(getline(srcCode, curLine)){
        if (debug)
            cout << curLine << endl;

        // Figure out if this is a line for annotation
        for (int i = 0; i < curLine.length(); i++){
            // if a tab or space is present ignore while no other chars are seen
            if ((curLine[i] == 32 || curLine[i] == 9 || curLine[i] == 11)){
                continue;
            }
            // first non-whitespace character seen
            else {
                // Check if line is comment
                if (curLine.find(commentSymbol) == i){
                    i += 1 + commentSymbol.length();
                    // Find if this comment follows the <comment_symbol> <annotation> format
                    // {START
                    if (curLine.find(START_STARTBLOCK) == i){
                        if (debug)
                            cout << "BEGIN START BLOCK" << endl;
                        inTuple = true;
                        ignore = true;
                    }
                    // START}
                    else if (curLine.find(END_STARTBLOCK) == i){
                        if (debug)
                            cout << "END START BLOCK" << endl;
                        inTuple = false;
                        ignore = true;
                    }
                    // {END
                    else if (curLine.find(START_ENDBLOCK) == i){
                        if (debug)
                            cout << "START END BLOCK" << endl;
                        inTuple = true;
                        ignore = true;
                    }
                    // END}
                    else if (curLine.find(END_ENDBLOCK) == i){
                        if (debug)
                            cout << "END END BLOCK" << endl;
                        inTuple = false;
                        ignore = true;
                    }
                    // {*
                    else if (curLine.find(START_TUPLE) == i){
                        if (debug)
                            cout << "START TUPLE BLOCK" << endl;
                        inTuple = true;
                        ignore = false;
                    }
                    // *}
                    else if (curLine.find(END_TUPLE) == i){
                        if (debug)
                            cout << "END TUPLEBLOCK" << endl;
                        inTuple = false;
                        ignore = false;
                    }
                    // Not an annotation line, regular comment
                    else {
                        curTuple += curLine + '\n';
                    }
                    break;
                }
                // Not a comment
                else {
                    curTuple += curLine + '\n';
                    break;
                }
            }
        }
        if (!inTuple){
            returnedCode->AddCodeTuple(curTuple, ignore);
            curTuple = "";
            ignore = false;
        }
    }

    // Close srcCode file
    srcCode.close();
    codeRep = returnedCode;

    return returnedCode;
}