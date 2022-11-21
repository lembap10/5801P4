#include <iostream>
#include "../include/DefaultCodeParser.h"

using namespace std;

void test_equivalence(void* actual, void* expected, string type, string testName){
    if (type == "string"){
        string actual_val = *(string*)actual;
        string expected_val = *(string*)expected;
        if (actual_val == expected_val){
            cout << "TEST PASSED : " << testName << endl; 
        }
        else {
            cout << "TEST FAILED : " << testName << endl; 
        }
    }
    else if (type == "vector<string>"){
        vector<string> actual_val = *(vector<string>*)actual;
        vector<string> expected_val = *(vector<string>*)expected;
        if (actual_val == expected_val){
            cout << "TEST PASSED : " << testName << endl; 
        }
        else {
            cout << "TEST FAILED : " << testName << endl; 
        }
    }
    else if (type == "vector<bool>"){
        vector<bool> actual_val = *(vector<bool>*)actual;
        vector<bool> expected_val = *(vector<bool>*)expected;
        if (actual_val == expected_val){
            cout << "TEST PASSED : " << testName << endl; 
        }
        else {
            cout << "TEST FAILED : " << testName << endl; 
        }
    }
    else if (type == "int"){
        int actual_val = *(int*)actual;
        int expected_val = *(int*)expected;
        if (actual_val == expected_val){
            cout << "TEST PASSED : " << testName << endl; 
        }
        else {
            cout << "TEST FAILED : " << testName << endl; 
        }
    }
    // else if (type == "DefaultCodeParser"){
    //     DefaultCodeParser actual_val = *(DefaultCodeParser*)actual;
    //     DefaultCodeParser expected_val = *(DefaultCodeParser*)expected;
    //     if (actual_val == expected_val){
    //         cout << "TEST PASSED : " << testName << endl; 
    //     }
    //     else {
    //         cout << "TEST FAILED : " << testName << endl; 
    //     }
    // }
    else if (type == "ParsedCode"){
        ParsedCode actual_val = *(ParsedCode*)actual;
        ParsedCode expected_val = *(ParsedCode*)expected;
        if (actual_val == expected_val){
            cout << "TEST PASSED : " << testName << endl; 
        }
        else {
            cout << "TEST FAILED : " << testName << endl; 
        }
    }
}
