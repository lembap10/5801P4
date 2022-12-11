#include "tester.h"
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream

using namespace std;

void AddTest()
{
    // Test for adding 1 tuple to empty object
    ParsedCode code1 = ParsedCode();
    code1.AddCodeTuple("line of code 1\n", false);
    int numTuples = code1.getNumTuples();
    int expectNumTuples = 1;
    string actual = code1.getLines()[0];
    string expect = "line of code 1\n";

    test_equivalence(&actual, &expect, "string", "PC300: Adding 1 tuple to empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC301: Adding 1 tuple to empty object: Number of tuples");

    // Test for adding 10000 tuples to empty object
    ParsedCode code2 = ParsedCode();
    for (int i = 0; i < 10000; i++)
    {
        code2.AddCodeTuple("line of code 1\n", false);
    }
    numTuples = code2.getNumTuples();
    expectNumTuples = 10000;
    actual = code2.getLines()[9999];
    expect = "line of code 1\n";

    test_equivalence(&actual, &expect, "string", "PC302: Adding 10000 tuples to empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC303: Adding 10000 tuples to empty object: Number of tuples");

    // Test for adding 1 tuple to non-empty object
    ParsedCode code3 = ParsedCode();
    code3.AddCodeTuple("line of code 1\n", false);
    code3.AddCodeTuple("line of code 2\n", false);
    numTuples = code3.getNumTuples();
    expectNumTuples = 2;
    actual = code3.getLines()[1];
    expect = "line of code 2\n";

    test_equivalence(&actual, &expect, "string", "PC304: Adding 1 tuple to non-empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC305: Adding 1 tuple to non-empty object: Number of tuples");

    // Test for adding 10000 tuples to non-empty object
    ParsedCode code4 = ParsedCode();
    code4.AddCodeTuple("line of code 1\n", false);
    for (int i = 0; i < 10000; i++)
    {
        code4.AddCodeTuple("line of code 2\n", false);
    }
    numTuples = code4.getNumTuples();
    expectNumTuples = 10001;
    actual = code4.getLines()[10000];
    expect = "line of code 2\n";

    test_equivalence(&actual, &expect, "string", "PC306: Adding 10000 tuples to non-empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC307: Adding 10000 tuples to non-empty object: Number of tuples");
}

void RemoveTest()
{
    // Test for removing 1 tuple from non-empty object
    ParsedCode code1 = ParsedCode();
    code1.AddCodeTuple("line of code 1\n", false);
    code1.AddCodeTuple("line of code 2\n", false);
    code1.RemoveCodeTuple(0);
    int numTuples = code1.getNumTuples();
    int expectNumTuples = 1;
    string actual = code1.getLines()[0];
    string expect = "line of code 2\n";

    test_equivalence(&actual, &expect, "string", "PC308: Removing 1 tuple from non-empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC309: Removing 1 tuple from non-empty object: Number of tuples");

    // Test for removing 10000 tuples from non-empty object
    ParsedCode code2 = ParsedCode();
    code2.AddCodeTuple("line of code 1\n", false);
    for (int i = 0; i < 10000; i++)
    {
        code2.AddCodeTuple("line of code 2\n", false);
    }
    for (int i = 0; i < 10000; i++)
    {
        code2.RemoveCodeTuple(0);
    }
    numTuples = code2.getNumTuples();
    expectNumTuples = 1;
    actual = code2.getLines()[0];
    expect = "line of code 1\n";

    test_equivalence(&actual, &expect, "string", "PC310: Removing 10000 tuples from non-empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC311: Removing 10000 tuples from non-empty object: Number of tuples");

    // Test for removing 1 tuple from empty object
    ParsedCode code3 = ParsedCode();
    code3.RemoveCodeTuple(0);
    numTuples = code3.getNumTuples();
    expectNumTuples = 0;
    bool actualBool = code3.getLines().empty();
    bool expectBool = true;

    test_equivalence(&actualBool, &expectBool, "bool", "PC312: Removing 1 tuple from empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC313: Removing 1 tuple from empty object: Number of tuples");

    // Test for removing 10000 tuples from empty object
    ParsedCode code4 = ParsedCode();
    for (int i = 0; i < 10000; i++)
    {
        code4.RemoveCodeTuple(0);
    }
    numTuples = code4.getNumTuples();
    expectNumTuples = 0;
    actualBool = code4.getLines().empty();
    expectBool = true;

    test_equivalence(&actualBool, &expectBool, "bool", "PC314: Removing 10000 tuples from empty object: String");
    test_equivalence(&numTuples, &expectNumTuples, "int", "PC315: Removing 10000 tuples from empty object: Number of tuples");
}

void wrongOrderAnnotationTest()
{
    // Initialization
    DefaultCodeParser parser;
    ParsedCode *code;
    // Test for annotation of wrong order
    code = parser.ParseCode("wrongOrderAnnotation.cpp");
    vector<string> expect = {"//This is a test file for testing PPALMS Program\n#include <iostream>\nusing namespace std;\n\nint main(){\n", "    int x = 0;\n    int y = 0;\n", "    int z = x + y;\n", "    cout << z;\n", "    return z;\n}\n"};
    vector<string> actual = code->getLines();

    test_equivalence(&actual, &expect, "vector<string>", "DCP316: Annotation of wrong order: String");
}

void wrongFileType()
{
    // Initialization
    DefaultCodeParser parser;
    ParsedCode *code;
    // Test for annotation of wrong file type
    code = parser.ParseCode("wrongFileType.cpp");
    vector<string> expect = {"# This is a test file for testing PPALMS Program\n\ndef main():\n", "    x = 0\n    y = 0\n", "    z = x + y\n", "    print(z)\n", "    return 0\n"};

    vector<string> actual = code->getLines();

    test_equivalence(&actual, &expect, "vector<string>", "DCP317: Wrong File type: String");
}

void YYTests()
{
    AddTest();
    RemoveTest();
    wrongOrderAnnotationTest();
    wrongFileType();
}