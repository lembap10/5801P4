#include "tester.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream

using namespace std;

void PrintTest(){
    // Initialization
    ParsedCode code1 = ParsedCode();
    
    // Test for printing empty object
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1.print();
    cout.rdbuf(prevcoutbuf);
    string actual = buffer.str();
    string expect = "Total Number of tuples: 0\n";
    
    test_equivalence(&actual, &expect, "string", "PC100: Printing empty object");

    // Test for printing object with 1 tuple with false ignore
    code1.AddCodeTuple("line of code 1", false);
    buffer = stringstream();
    prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1.print();
    cout.rdbuf(prevcoutbuf);
    actual = buffer.str();
    expect = "Total Number of tuples: 1\n1: DO NOT IGNORE\nline of code 1\n";
   
    test_equivalence(&actual, &expect, "string", "PC101: Printing object with 1 tuple with false ignore");

    // Test for printing object with 1 tuple with true ignore
    code1.RemoveCodeTuple(0);
    code1.AddCodeTuple("line of code 1", true);
    buffer = stringstream();
    prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1.print();
    cout.rdbuf(prevcoutbuf);
    actual = buffer.str();
    expect = "Total Number of tuples: 1\n1: IGNORE\nline of code 1\n";
    
    test_equivalence(&actual, &expect, "string", "PC102: Printing object with 1 tuple with true ignore");

    // Test for printing objet with 2 tuples, one true and one false
    code1.AddCodeTuple("line of code 2", false);
    buffer = stringstream();
    prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code1.print();
    cout.rdbuf(prevcoutbuf);
    actual = buffer.str();
    expect = "Total Number of tuples: 2\n1: IGNORE\nline of code 1\n2: DO NOT IGNORE\nline of code 2\n";
    test_equivalence(&actual, &expect, "string", "PC103: Printing object with 2 tuples of different ignores");
}

void ParsedCodeTest(){
    // Initialization
    DefaultCodeParser parser;
    ParsedCode *code;

    // Test for parsing invalid file type with correct annotation
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    code = parser.ParseCode("srcFiles/test.ml");
    cout.rdbuf(prevcoutbuf);
    string actual = buffer.str();
    string expect = "Error: Invalid file type\n";

    if(code == NULL && actual == expect){
        cout << "  TEST PASSED : DCP110: Parsing invalid file type with correct annotation" << endl;
    }
    else{
        cout << "X TEST FAILED : DCP110: Parsing invalid file type with correct annotation" << endl;
    }
    
    // Test for java file
    code = parser.ParseCode("srcFiles/Test.java");
    vector<string> a = code->getLines();
    vector<string> e = {"package srcFiles;\n", "// This is a test file for testing PPALMS Program\npublic class Test{\n    public static void main(String[] args){\n", "    int x = 0;\n    int y = 0;\n", "    int z = x + y;\n", "    System.out.println(z);\n","    }\n}\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP111: Parsing java file");

    // Test for c++ file
    code = parser.ParseCode("srcFiles/test.cpp");
    a = code->getLines();
    e = {"//This is a test file for testing PPALMS Program\n#include <iostream>\nusing namespace std;\n\nint main(){\n", "    int x = 0;\n    int y = 0;\n", "    int z = x + y;\n", "    cout << z;\n","    return z;\n}\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP112: Parsing c++ file");

    // Test for c file
    code = parser.ParseCode("srcFiles/test.c");
    a = code->getLines();
    e = {"// This is a test file for testing PPALMS Program\n#include <stdio.h>\nint main() {\n", "  int x = 0;\n  int y = 0;\n", "  int z = x + y;\n", "  printf(\"%d\", z);\n","  return z;\n}\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP113: Parsing c file");

    // Test for cc file
    code = parser.ParseCode("srcFiles/test.cc");
    a = code->getLines();
    e = {"//This is a test file for testing PPALMS Program\n#include <iostream>\nusing namespace std;\n\nint main(){\n", "    int x = 0;\n    int y = 0;\n", "    int z = x + y;\n", "    cout << z;\n","    return z;\n}\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP114: Parsing cc file");

    // Test for cs file
    code = parser.ParseCode("srcFiles/test.cs");
    a = code->getLines();
    e = {"// This is a test file for testing PPALMS Program\nusing System;\nnamespace test\n{\n  class Test\n  {\n    static void Main(string[] args)\n    {\n", "      int x = 0;\n      int y = 0;\n", "      int z = x + y;\n", "      Console.WriteLine(z);\n","    }\n  }\n}\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP115: Parsing cs file");

    // Test for h file
    code = parser.ParseCode("srcFiles/test.h");
    a = code->getLines();
    e = {"// This is a test file for testing PPALMS Program\n#include <iostream>\nusing namespace std;\n\nint main(){\n", "    int x = 0;\n    int y = 0;\n", "    int z = x + y;\n", "    cout << z;\n","    return z;\n}\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP116: Parsing h file");

    // Test for py file
    code = parser.ParseCode("srcFiles/test.py");
    a = code->getLines();
    e = {"# This is a test file for testing PPALMS Program\n\ndef main():\n", "    x = 0\n    y = 0\n", "    z = x + y\n", "    print(z)\n", "    return 0\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP117: Parsing py file");

    // Test for js file
    code = parser.ParseCode("srcFiles/test.js");
    a = code->getLines();
    e = {"// This is a test file for testing PPALMS Program\nclass Test {}\nTest.main = (args) => {\n", "  let x = 0;\n  let y = 0;\n", "  let z = x + y;\n", "  console.log(z);\n", "  return z;\n};\n"};
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < a.size(); i++){
    //     cout << i << a[i];
    // }
    // cout << "Size: " << a.size() << endl;
    // for(int i = 0; i < e.size(); i++){
    //     cout << i << e[i];
    // }
    // for(int i = 0; i < a.size(); i++){
    //     if(a[i] != e[i]){
    //         cout << i << a[i] << endl << i << e[i] << endl;
    //     }
    // }
    test_equivalence(&a, &e, "vector<string>", "DCP118: Parsing js file");

    // Test for empty file
    code = parser.ParseCode("srcFiles/empty.java");
    if(code == NULL){
        cout << "  TEST PASSED : DCP119: Parsing an empty file" << endl;
    }
    else{
        cout << "X TEST FAILED : DCP119: Parsing an empty file" << endl;
    }

    // Test for non existent file
    code = parser.ParseCode("srcFiles/nonExistent.java");
    if(code == NULL){
        cout << "  TEST PASSED : DCP120: Parsing a non existent file" << endl;
    }
    else{
        cout << "X TEST FAILED : DCP120: Parsing a non existent file" << endl;
    }

    // Test for one-line file
    code = parser.ParseCode("srcFiles/oneLine.py");
    if(code == NULL){
        cout << "  TEST PASSED : DCP121: Parsing an one-line file" << endl;
    }
    else{
        cout << "X TEST FAILED : DCP121: Parsing an one-line file" << endl;
    }

}

void NLTests(){
    PrintTest();
    ParsedCodeTest();
}
