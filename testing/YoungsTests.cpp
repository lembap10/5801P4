#include "tester.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream

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
    test_equivalence(&numLines, &expectedLines, "int", "PC200");
    test_equivalence(&reglines, &expectedreglines, "vector<string>", "PC201");
    test_equivalence(&ignoredLines, &expectediglines, "vector<bool>", "PC202");
}

void testgetNumTuples(){
    ParsedCode parser = ParsedCode();
    int numLines;
    parser.AddCodeTuple("aaa", false);
    numLines = parser.getNumTuples();
    int expectedLines;
    expectedLines = 1;
    test_equivalence(&numLines, &expectedLines, "int", "PC203");
    parser.RemoveCodeTuple(0);
    numLines = parser.getNumTuples();
    expectedLines = 0;
    test_equivalence(&numLines, &expectedLines, "int", "PC204");
}

void testgetlines(){
    ParsedCode parser = ParsedCode();
    parser.AddCodeTuple("aaa", false);
    vector<string> reglines;
    reglines = parser.getLines();
    vector<string> expectedLines {"aaa"};
    test_equivalence(&reglines, &expectedLines, "vector<string>", "PC205");
    parser.RemoveCodeTuple(0);
    vector<string> reglines1 = parser.getLines();
    vector<string> expectedLines1;
    test_equivalence(&reglines1, &expectedLines1, "vector<string>", "PC206");
}

void testgetbool(){
    ParsedCode parser = ParsedCode();
    parser.AddCodeTuple("aaa", false);
    parser.AddCodeTuple("aaa", true);
    vector<bool> reglines;
    reglines = parser.getIgnores();
    vector<bool> expectedLines {false, true};
    test_equivalence(&reglines, &expectedLines, "vector<bool>", "PC207");
    parser.RemoveCodeTuple(0);
    parser.RemoveCodeTuple(0);
    vector<bool> reglines1 = parser.getIgnores();
    vector<bool> expectedLines1;
    test_equivalence(&reglines1, &expectedLines1, "vector<bool>", "PC208");
}

void trickyAnnotationDefaultParserTest(){
    DefaultCodeParser defaultParser;
    ParsedCode *code;
    code = defaultParser.ParseCode("srcFiles/trickyAnnotation.cpp");
    vector<string> a = code->getLines();
    vector<string> expectedVec = {"// This is a test file for testing PPALMS Program\n#include <iostream>\nusing namespace std;\nint main(){\n","","","","    int x = 0;\n    int y = 0;\n","","","    int z = x + y;\n","    cout << z;\n","    return z;\n}\n"};
    test_equivalence(&a, &expectedVec, "vector<string>", "DCP209");
    vector<bool> b = code->getIgnores();
    vector<bool> expectedBool = {1,0,0,0,0,0,0,0,0,1};
    test_equivalence(&b, &expectedBool, "vector<bool>", "DCP210");

}

void missingBlockAnnotationDefaultParserTest(){
    DefaultCodeParser defaultParser;
    ParsedCode *code1;
    code1 = defaultParser.ParseCode("srcFiles/trickyAnnotationOneBlock.cpp");
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1->print();
    cout.rdbuf(prevcoutbuf);
    string actual = buffer.str();

    string expect = "Error: Unmatched Annotations";
    test_equivalence(&actual, &expect, "string", "DCP211");

}

void NoAnnotationDefaultParserTest(){
    DefaultCodeParser defaultParser;
    ParsedCode *code;
    code = defaultParser.ParseCode("srcFiles/noannotations.cpp");
    vector<string> a = code->getLines();
    vector<string> expectedVec = {"#include <iostream>\n","using namespace std;\n","","int main(){\n","    int x = 0;\n","    int y = 0;\n","    int z = x + y;\n","    cout << z;\n","    return z;\n","}\n"};
    test_equivalence(&a, &expectedVec, "vector<string>", "DCP212");
    vector<bool> b = code->getIgnores();
    vector<bool> expectedBool = {0,0,0,0,0,0,0,0,0,0};
    test_equivalence(&b, &expectedBool, "vector<bool>", "DCP213");

}

void YXTests(){
    testConstructor();
    testgetNumTuples();
    testgetlines();
    testgetbool();
    trickyAnnotationDefaultParserTest();
    missingBlockAnnotationDefaultParserTest();
    NoAnnotationDefaultParserTest();
}



