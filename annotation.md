# PPALMS Software Annotation Standard  

The following is how to annotate files of source code such that the PPALMS system can properly parse it. This includes the exlusion, and grouping of lines in the original code.

This document describing the annotation works with various source code file types. The allowed files are: .cpp, .c, .cs, .cc, .h, .java, .py, .js

The value <comment_symbol> will represent the characters needed to start a comment in various lamguages.  
These are:
- "//" for .cpp, .c, .cs, .cc, .h, .js, .java  
- "#" for .py  

### Annotations  

The annotation is to be written in a comment. An annotation would look like  
```
<comment_symbol> <annotation>
```

Comments that are written for problem generation __will not__ be included in the created problems.  



#### Example
Suppose a file call it test.cpp is: 
```
{START
// This is a test file for testing PPALMS Program
#include <iostream>
using namespace std;

int main(){
    // START}
    // {*
    int x = 0;
    int y = 0;
    // *}
    int z = x + y;
    cout << z;
    // {END
    return z;
}
// END}
```