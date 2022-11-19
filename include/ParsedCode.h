#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ParsedCode{
    private:
        int numLines;
        vector<string> lines;
        vector<bool> ignored;
    public:
        ParsedCode();
        void AddCodeTuple (string line, bool ignore);
        void RemoveCodeTuple (int tupleNum);
        vector<string> getLines();
        int getNumTuples();
        vector<bool> getIgnores();
        void print();
};
