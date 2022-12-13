#include "../include/JSONGenerator.h"
#include <vector>

JSONGenerator::JSONGenerator(Params* param){
    // Push the attributes to its vectors for every important field valid in both question types
    jsonAttributes.push_back({ "numStudents", to_string(param->getNumStudents())});
    jsonAttributes.push_back({ "questionType", param->getQuestionType()});
    jsonAttributes.push_back({ "intendedLMS", param->getIntendedLMS()});
    jsonAttributes.push_back({ "intendedQuizType", param->getIntendedQuizType()});
    // add the printed version of the code to use for questions
    string code = param->getSourceCode()->stringRep();
    jsonAttributes.push_back({ "code", code});
    // add an array of 1s and 0s to show what lines to ignore
    string ign = param->getSourceCode()->stringIgn();
    jsonAttributes.push_back({ "ignoreLines", ign});
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
        // for last element, don't add comma
        if (i == jsonAttributes.size()-1){
            infile << "\t\"" << jsonAttributes[i][0] << "\": \"" << jsonAttributes[i][1] << "\""<< endl;
        }
        // Do not put " for array elements
        else if (jsonAttributes[i][0] == "code" || jsonAttributes[i][0] == "ignoreLines"){
            infile << "\t\"" << jsonAttributes[i][0] << "\": " << jsonAttributes[i][1] << endl;
        }
        else{
            infile << "\t\"" << jsonAttributes[i][0] << "\": \"" << jsonAttributes[i][1] << "\","<< endl;
        }
    }
    infile << "}" << endl;
    return fileName;
}