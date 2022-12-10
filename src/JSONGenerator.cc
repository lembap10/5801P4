#include "../include/JSONGenerator.h"
#include <vector>

JSONGenerator::JSONGenerator(Params* param){
    jsonAttributes.push_back({ "numStudents", to_string(param->getNumStudents())});
    jsonAttributes.push_back({ "questionType", param->getQuestionType()});
    jsonAttributes.push_back({ "intendedLMS", param->getIntendedLMS()});
    jsonAttributes.push_back({ "intendedQuizType", param->getIntendedQuizType()});
}

// returns filename of new JSON file
string JSONGenerator::createJSONFile(){
    time_t now = time(0);
    string fileName = to_string(now) + ".json";
    
    // create and open 
    ofstream infile;
    infile.open("json/"+ fileName);

    infile << "{" << endl;
    for (int i = 0 ; i < jsonAttributes.size(); i++){
        infile << "\"" << jsonAttributes[i][0] << "\": \"" << jsonAttributes[i][1] << "\","<< endl;
    }
    infile << "}" << endl;
    return fileName;
}