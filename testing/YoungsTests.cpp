#include "tester.h"

using namespace std;

void testConstructor(){
    ParsedCode parser = ParsedCode();
    int numLines;
    numLines = parser.getNumTuples();
    int expectedLines;
    expectedLines = 0;
    vector<string> reglines;
    reglines = parser.getLines();
    vector<string> expectedreglines;
    vector<bool> ignoredLines;
    ignoredLines = parser.getIgnores();
    vector<bool> expectediglines;
    test_equivalence(&numLines, &expectedLines, "int", "ConstructorTestnumLines");
    test_equivalence(&reglines, &expectedreglines, "vector<string>", "ConstructorTestregvector");
    test_equivalence(&ignoredLines, &expectediglines, "vector<bool>", "ConstructorTestignoredvector");
}

void testgetNumTuples(){
    ParsedCode parser = ParsedCode();
    int numLines;
    parser.AddCodeTuple("aaa", false);
    numLines = parser.getNumTuples();
    int expectedLines;
    expectedLines = 1;
    test_equivalence(&numLines, &expectedLines, "int", "ConstructorTestGetNumLines");
    parser.RemoveCodeTuple(0);
    numLines = parser.getNumTuples();
    expectedLines = 0;
    test_equivalence(&numLines, &expectedLines, "int", "ConstructorTestGetnumLinesnone");
}

void testgetlines(){
    ParsedCode parser = ParsedCode();
    parser.AddCodeTuple("aaa", false);
    vector<string> reglines;
    reglines = parser.getLines();
    vector<string> expectedLines {"aaa"};
    test_equivalence(&reglines, &expectedLines, "vector<string>", "ConstructorTestGetStringVector");
    parser.RemoveCodeTuple(0);
    vector<string> reglines1 = parser.getLines();
    vector<string> expectedLines1;
    test_equivalence(&reglines1, &expectedLines1, "vector<string>", "ConstructorTestGetStringVectornone");
}

void testgetbool(){
    ParsedCode parser = ParsedCode();
    parser.AddCodeTuple("aaa", false);
    vector<bool> reglines;
    reglines = parser.getIgnores();
    vector<bool> expectedLines {false};
    test_equivalence(&reglines, &expectedLines, "vector<bool>", "ConstructorTestGetBoolVector");
    parser.RemoveCodeTuple(0);
    vector<bool> reglines1 = parser.getIgnores();
    vector<bool> expectedLines1;
    test_equivalence(&reglines1, &expectedLines1, "vector<bool>", "ConstructorTestGetBoolVectornone");
}


void YXTests(){
    testConstructor();
    testgetNumTuples();
    testgetlines();
    testgetbool();
}



