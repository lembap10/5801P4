#include "../include/ParsedCode.h"
using namespace std;
/**
 * @brief Default Constructor, initializes both vector attributes and numLines to 0
 * 
 */
ParsedCode::ParsedCode(){
    numLines = 0;
    lines = vector<string>();
    ignored = vector<bool>();
}

/**
 * @brief Adds a tuple (string) to the lines vector
 * 
 * @param line string to add
 * @param ignore should this line be ignored
 */
void ParsedCode::AddCodeTuple (string line, bool ignore){
    // Push the line to the vector, and the ignore val, add 1 to the size
    lines.push_back(line);
    numLines++;
    ignored.push_back(ignore);
}

/**
 * @brief removes a tuple from the vector lines
 * 
 * @param tupleNum tuple to remove
 */
void ParsedCode::RemoveCodeTuple (int tupleNum){
    if (tupleNum < 0 || tupleNum >= numLines){
        return;
    }
    lines.erase(lines.begin() + tupleNum);
    ignored.erase(ignored.begin() + tupleNum);
    numLines--;
}

/**
 * @brief gives the vector of lines
 * 
 * @return vector<string> value of lines 
 */
vector<string> ParsedCode::getLines(){
    return lines;
}

/**
 * @brief gives the number of tuples
 * 
 * @return int value of numLines 
 */
int ParsedCode::getNumTuples(){
    return numLines;
}

/**
 * @brief gives the vector representing the lines to ignore
 * 
 * @return vector<bool> 
 */
vector<bool> ParsedCode::getIgnores(){
    return ignored;
}

/**
 * @brief Debugging function to print the representation of the parsed code
 * prints out all information to verify the parsed code
 */
void ParsedCode::print(){
    cout << "Total Number of tuples: " << numLines << endl;
    for (int i = 0; i < numLines; i++){
        cout << i+1 << ": ";
        if (ignored[i]){
            cout << "IGNORE" << endl; 
        }
        else {
            cout << "DO NOT IGNORE" << endl;
        }
        cout << lines[i] << endl;
    }
}

// Returns a representation of the code which can be easily added to a 
string ParsedCode::stringRep(){
    string ret = "[\n";
    for (int i = 0 ; i < lines.size(); i++){
        ret += ("\t\t\"" + lines[i] + "\\n");
        if (i != numLines-1)
            ret += "\",\n";
        else 
            ret += "\"";
    }
    ret += "],";
    return ret;
}

// Returns array of true or false values
string ParsedCode::stringIgn(){
    string ret = "[";
    for (int i = 0 ; i < ignored.size(); i++){
        if (ignored[i])
            ret += ("\"1");
        else 
            ret += ("\"0");
        if (i != numLines-1)
            ret += "\",";
        else 
            ret += "\"";
    }
    ret += "],";
    return ret;
}