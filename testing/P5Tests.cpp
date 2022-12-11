#include "tester.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include <fstream>
#include <vector>
#include "../include/JSONGenerator.h"
#include "../include/Params.h"
#include <cassert>

using namespace std;

// Test the JsonGenerator class
void testJsonGenerator()
{
}
void testCreateJSONFile()
{
}
// Test the Params class
void testParams()
{
    // Test the constructor
    ParsedCode *sourceCode = new ParsedCode();
    Params *param = new Params(1, "questionType", sourceCode, "intendedLMS", "intendedQuizType");
    // assert(param->getNumStudents() == 1);
    int numStudents = param->getNumStudents();
    int expectednumStudents = 1;
    test_equivalence(&numStudents, &expectednumStudents, "int", "P001: Test the constructor: numStudents");

    // assert(param->getQuestionType() == "questionType");
    string questionType = param->getQuestionType();
    string expectedQuestionType = "questionType";
    test_equivalence(&questionType, &expectedQuestionType, "string", "P002: Test the constructor: questionType");
    bool boolCode = true;
    if (param->getSourceCode() != sourceCode)
    {
        bool boolCode = false;
    }
    bool exptedboolCode = true;
    test_equivalence(&boolCode, &exptedboolCode, "bool", "P003: Test the constructor: sourceCode");
    // assert(param->getIntendedLMS() == "intendedLMS");
    string intendedLMS = param->getIntendedLMS();
    string expectedintendedLMS = "intendedLMS";
    test_equivalence(&intendedLMS, &expectedintendedLMS, "string", "P004: Test the constructor: intendedLMS");
    // assert(param->getIntendedQuizType() == "intendedQuizType");
    string intendedQuizType = param->getIntendedQuizType();
    string expectedintendedQuizType = "intendedQuizType";
    test_equivalence(&intendedQuizType, &expectedintendedQuizType, "string", "P005: Test the constructor: intendedQuizType");
    //  Test the setters
    param->setNumStudents(2);
    param->setQuestionType("questionType2");
    param->setSourceCode(sourceCode);
    param->setIntendedLMS("intendedLMS2");
    param->setIntendedQuizType("intendedQuizType2");
    // assert(param->getNumStudents() == 2);
    int numStudents2 = param->getNumStudents();
    int expectednumStudents2 = 2;
    test_equivalence(&numStudents2, &expectednumStudents2, "int", "P006: Test the setters: numStudents");
    // assert(param->getQuestionType() == "questionType2");
    string questionType2 = param->getQuestionType();
    string expectedQuestionType2 = "questionType2";
    test_equivalence(&questionType2, &expectedQuestionType2, "string", "P007: Test the setters: questionType");
    // assert(param->getSourceCode() == sourceCode);
    bool boolCode2 = true;
    if (param->getSourceCode() != sourceCode)
    {
        bool boolCode2 = false;
    }
    bool exptedboolCode2 = true;
    test_equivalence(&boolCode2, &exptedboolCode2, "bool", "P008: Test the setters: sourceCode");
    // assert(param->getIntendedLMS() == "intendedLMS2");
    string intendedLMS2 = param->getIntendedLMS();
    string expectedintendedLMS2 = "intendedLMS2";
    test_equivalence(&intendedLMS2, &expectedintendedLMS2, "string", "P009: Test the setters: intendedLMS");
    // assert(param->getIntendedQuizType() == "intendedQuizType2");
    string intendedQuizType2 = param->getIntendedQuizType();
    string expectedintendedQuizType2 = "intendedQuizType2";
    test_equivalence(&intendedQuizType2, &expectedintendedQuizType2, "string", "P010: Test the setters: intendedQuizType");
}

void P5tests()
{
    testJsonGenerator();
    testCreateJSONFile();
    testParams();
}