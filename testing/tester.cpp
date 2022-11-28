#include <iostream>
#include "../include/DefaultCodeParser.h"

using namespace std;

const string PASSED = "  TEST PASSED : ";
const string FAILED = "X TEST FAILED : ";

// Testing to equivanlence
void test_equivalence(void *actual, void *expected, string type, string testName)
{
    if (type == "string")
    {
        string actual_val = *(string *)actual;
        string expected_val = *(string *)expected;
        if (actual_val == expected_val)
        {
            cout << PASSED << testName << endl;
        }
        else
        {
            cout << FAILED << testName << endl;
        }
    }
    else if (type == "vector<string>")
    {
        vector<string> actual_val = *(vector<string> *)actual;
        vector<string> expected_val = *(vector<string> *)expected;
        if (actual_val == expected_val)
        {
            cout << PASSED << testName << endl;
        }
        else
        {
            cout << FAILED << testName << endl;
        }
    }
    else if (type == "vector<bool>")
    {
        vector<bool> actual_val = *(vector<bool> *)actual;
        vector<bool> expected_val = *(vector<bool> *)expected;
        if (actual_val == expected_val)
        {
            cout << PASSED << testName << endl;
        }
        else
        {
            cout << FAILED << testName << endl;
        }
    }
    else if (type == "bool")
    {
        bool actual_val = *(bool *)actual;
        bool expected_val = *(bool *)expected;
        if (actual_val == expected_val)
        {
            cout << PASSED << testName << endl;
        }
        else
        {
            cout << FAILED << testName << endl;
        }
    }
    else if (type == "int")
    {
        int actual_val = *(int *)actual;
        int expected_val = *(int *)expected;
        if (actual_val == expected_val)
        {
            cout << PASSED << testName << endl;
        }
        else
        {
            cout << FAILED << testName << endl;
        }
    }
    else if (type == "ParsedCode")
    {
        ParsedCode actual_val = *(ParsedCode *)actual;
        ParsedCode expected_val = *(ParsedCode *)expected;
        if (actual_val == expected_val)
        {
            cout << PASSED << testName << endl;
        }
        else
        {
            cout << FAILED << testName << endl;
        }
    }
}
