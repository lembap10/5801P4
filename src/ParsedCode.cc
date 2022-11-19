#include "../include/ParsedCode.h"
using namespace std;
/**
 * @brief Construct a new Parsed Code:: Parsed Code object
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
    lines.erase(lines.begin() + tupleNum);
    ignored.erase(ignored.begin() + tupleNum);
}

/**
 * @brief gives the vector of lines
 * 
 * @return vector<string> 
 */
vector<string> ParsedCode::getLines(){
    return lines;
}

/**
 * @brief gives the number of tuples
 * 
 * @return int 
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
 * 
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