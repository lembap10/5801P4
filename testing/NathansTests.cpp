#include "tester.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream

using namespace std;

void PrintTest(ParsedCode code1, ParsedCode code2){
    // PRINT TESTING for equal outputs
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1.print();
    cout.rdbuf(prevcoutbuf);
    string actual = buffer.str();

    buffer = stringstream();
    prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code2.print();
    cout.rdbuf(prevcoutbuf);
    string expect = buffer.str();
    
    test_equivalence(&actual, &expect, "string", "Test #1: Testing 2 equal outputs(Expect pass)");

    // PRINT TESTING for unequal outputs
    code1.AddCodeTuple("1", false);
    buffer = stringstream();
    prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1.print();
    cout.rdbuf(prevcoutbuf);
    actual = buffer.str();

    buffer = stringstream();
    prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code2.print();
    cout.rdbuf(prevcoutbuf);
    expect = buffer.str();
    
    test_equivalence(&actual, &expect, "string", "Test #1: Testing 2 not equal outputs(Expect fail)");

}

void NLTests(){

    ParsedCode code1 = ParsedCode();
    ParsedCode code2 = ParsedCode();
    code1.AddCodeTuple("line of code 1", false);
    code2.AddCodeTuple("line of code 1", false);
    code1.AddCodeTuple("anotha line", false);
    code1.RemoveCodeTuple(1);
    cout << "Begin PRINT Test" << endl;
    PrintTest(code1, code2);
}

