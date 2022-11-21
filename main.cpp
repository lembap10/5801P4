#include "include/DefaultCodeParser.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream
#include "testing/tester.h"

using namespace std;

int main(){
    ParsedCode* code;
    DefaultCodeParser parser;

    // STRING TESTING
    string string_1 = "yo";
    string string_2 = "yo";
    string string_3 = "yop";
    test_equivalence(&string_1, &string_2, "string", "Testing 2 equal strings");
    test_equivalence(&string_1, &string_3, "string", "Testing 2 non-equal strings");

    // PARSEDCODE TESTING
    ParsedCode code1 = ParsedCode();
    ParsedCode code2 = ParsedCode();
    code1.AddCodeTuple("line of code 1", false);
    code2.AddCodeTuple("line of code 1", false);
    test_equivalence(&code1, &code2, "ParsedCode", "Testing simple 1 line code");

    code1.AddCodeTuple("anotha line", false);
    code1.RemoveCodeTuple(1);
    test_equivalence(&code1, &code2, "ParsedCode", "Testing adding and removing 1 line of code");

    // cout << "Enter file name to test: " ;
    // string fileName;
    // cin >> fileName;
    // code = parser.ParseCode("srcFiles/" + fileName);
    // if (code == NULL){
    //     cout << "Error while parsing" << endl;
    // }
    // else {
    //     code->print();
    // }

    // PRINT TESTING
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
    
    test_equivalence(&actual, &expect, "string", "Testing 2 equal outputs");
}