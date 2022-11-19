#include "include/ParsedCode.h"
using namespace std;

int main(){
    cout << "Starting main" << endl;
    ParsedCode code;
    code.AddCodeTuple("line 1\n", true);
    code.AddCodeTuple("line 2\nline3\n", false);
    code.AddCodeTuple("line 4\n", false);
    code.AddCodeTuple("line5\nline6\n", false);
    code.AddCodeTuple("line7", false);
    code.print();
}