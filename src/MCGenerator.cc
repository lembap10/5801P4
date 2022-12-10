#include "../include/MCGenerator.h"
using namespace std;

void MCGenerator::PopulateAttributes(){
    jsonAttributes.push_back({ "numChoices", to_string(numChoices)});
}