#include "../include/FillInBlanksGenerator.h"
using namespace std;



void FillInBlanksGenerator::PopulateAttributes(){
    jsonAttributes.push_back({ "blankLength", to_string(blankLength)});
}