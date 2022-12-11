#include "tester.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream

using namespace std;

void testConstructor()
{
    // These three tests test if the Constructor
    // is correctly initializing all values for ParsedCode

    // Test Setup
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

    // Comparing expected values
    test_equivalence(&numLines, &expectedLines, "int", "PC200: numLines attribute successfully initialized");
    test_equivalence(&reglines, &expectedreglines, "vector<string>", "PC201: lines attribute successfully initialized");
    test_equivalence(&ignoredLines, &expectediglines, "vector<bool>", "PC202: ignored attribute successfully initialized");
}

void testgetNumTuples()
{
    // These tests test if the getter for the
    // numTuples attribute is working correctly

    // Test setup
    ParsedCode parser = ParsedCode();
    int numLines;
    parser.AddCodeTuple("aaa", false);
    numLines = parser.getNumTuples();
    int expectedLines;
    expectedLines = 1;

    // Test if adding a code tuple returns expected value 1
    test_equivalence(&numLines, &expectedLines, "int", "PC203: numLines getter returns expected value 1 after adding tuple");
    parser.RemoveCodeTuple(0);
    numLines = parser.getNumTuples();
    expectedLines = 0;

    // Test if removing a code tuple returns expected value 1
    test_equivalence(&numLines, &expectedLines, "int", "PC204: numLines getter returns expected value 0 after removing 1 tuple");
}

void testgetlines()
{
    // These tests test if the getter for the
    // lines attribute is working correctly

    // Test setup
    ParsedCode parser = ParsedCode();
    parser.AddCodeTuple("aaa", false);
    vector<string> reglines;
    reglines = parser.getLines();
    vector<string> expectedLines{"aaa"};

    // Tests if getter returns vector with a string element
    test_equivalence(&reglines, &expectedLines, "vector<string>", "PC205: lines getter returns vector with added string element after adding tuple");
    parser.RemoveCodeTuple(0);
    vector<string> reglines1 = parser.getLines();
    vector<string> expectedLines1;

    // Test if getter returns empty vector after string element is removed
    test_equivalence(&reglines1, &expectedLines1, "vector<string>", "PC206: lines getter returns empty vector removing tuple");
}

void testgetbool()
{
    // These tests test if the getter for the
    // ignores attribute is working correctly

    // Test setup
    ParsedCode parser = ParsedCode();
    parser.AddCodeTuple("aaa", false);
    parser.AddCodeTuple("aaa", true);
    vector<bool> reglines;
    reglines = parser.getIgnores();
    vector<bool> expectedLines{false, true};

    // Test if upon insertion, a vector with a bool element is returned
    test_equivalence(&reglines, &expectedLines, "vector<bool>", "PC207: ignored getter returns vector expected boolean after adding tuple");
    parser.RemoveCodeTuple(0);
    parser.RemoveCodeTuple(0);
    vector<bool> reglines1 = parser.getIgnores();
    vector<bool> expectedLines1;

    // Test if upon removal of said bool, getter returns empty element
    test_equivalence(&reglines1, &expectedLines1, "vector<bool>", "PC208: ignored getter returns empty vector after removing tuple");
}

void trickyAnnotationDefaultParserTest()
{
    // These tests test if any "tricky" annotation will
    // mess up the parser for DefaultCodeParser

    // Test setup
    DefaultCodeParser defaultParser;
    ParsedCode *code;
    code = defaultParser.ParseCode("trickyAnnotation.cpp");
    vector<string> a = code->getLines();
    vector<string> expectedVec = {"// This is a test file for testing PPALMS Program\n#include <iostream>\nusing namespace std;\nint main(){\n", "", "", "", "    int x = 0;\n    int y = 0;\n", "", "", "    int z = x + y;\n", "    cout << z;\n", "    return z;\n}\n"};

    // Checks that upon parsing a file with spaces all around the annotations, the vector lines contains the correct elements
    test_equivalence(&a, &expectedVec, "vector<string>", "DCP209: Additional spaces around annotations do not affect parsing into lines attribute");
    vector<bool> b = code->getIgnores();
    vector<bool> expectedBool = {1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    // Checks that upon parsing a file with spaces all around the annotations, the vector ignores contains the correct bools
    test_equivalence(&b, &expectedBool, "vector<bool>", "DCP210: Additional spaces around annotations do not affect parsing into ignored attribute");
}

void missingBlockAnnotationDefaultParserTest()
{
    // These tests test if missing annotation blocks will
    // mess up the parser for DefaultCodeParser

    // Test setup
    DefaultCodeParser defaultParser;
    ParsedCode *code1;
    code1 = defaultParser.ParseCode("trickyAnnotationOneBlock.cpp");
    stringstream buffer;
    streambuf *prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1->print();
    cout.rdbuf(prevcoutbuf);
    string actual = buffer.str();
    string expect = "Error: Unmatched Annotations";

    // If successful, returns an error due to unmatched annotation blocks
    test_equivalence(&actual, &expect, "string", "DCP211: Having missing/incorrect annotations results in error message");
}

void NoAnnotationDefaultParserTest()
{
    // These tests test if a no annotation file will
    // parse correctly for DefaultCodeParser

    // Test setup
    DefaultCodeParser defaultParser;
    ParsedCode *code;
    code = defaultParser.ParseCode("noannotations.cpp");
    vector<string> a = code->getLines();
    vector<string> expectedVec = {"#include <iostream>\n", "using namespace std;\n", "", "int main(){\n", "    int x = 0;\n", "    int y = 0;\n", "    int z = x + y;\n", "    cout << z;\n", "    return z;\n", "}\n"};

    // Test if contents in line are correct
    test_equivalence(&a, &expectedVec, "vector<string>", "DCP212: Check that line attribute has correct elements with no annotations");
    vector<bool> b = code->getIgnores();
    vector<bool> expectedBool = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Test if contents in ignores are correct
    test_equivalence(&b, &expectedBool, "vector<bool>", "DCP213: Check that ignored attribute has all false elements with no annotations");
}

void YXTests()
{
    // Run all Young's Tests
    testConstructor();
    testgetNumTuples();
    testgetlines();
    testgetbool();
    trickyAnnotationDefaultParserTest();
    missingBlockAnnotationDefaultParserTest();
    NoAnnotationDefaultParserTest();
}
