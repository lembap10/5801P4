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
<comment_symbol> <annotation_symbol>
```  
space and tabs are permitted prior to comment symbol, and one and only one space should be included in between comment_symbol and annotation_symbol.  

The annottation symbols are as follow:  
- ```{START```  
    - Used to indicate the start of a block that should remain at the start of code
    - In the context of Parson's Problem, the start block shall always be at the start of the code even after rearraging the order of lines
- ```START}```  
    - Used to indicate the end of a block that should remain at the start of code
    - In the context of Parson's Problem, the start block shall always be at the start of the code even after rearraging the order of lines
- ```{END```
    - Used to indicate the start of a block that should remain at the end of code
    - In the context of Parson's Problem, the start block shall always be at the end of the code even after rearraging the order of lines
- ```END}```
    - Used to indicate the end of a block that should remain at the start of code
    - In the context of Parson's Problem, the start block shall always be at the end of the code even after rearraging the order of lines
- ```{*```
    - Used to indicate the start of a tuple of lines  
    - In the context of Parson's Problem, these tuples will retain the same order of lines within themselves, but different tuples will be rearranged
- ```*}```
    - Used to indicate the start of a tuple of lines  
    - In the context of Parson's Problem, these tuples will retain the same order of lines within themselves, but different tuples will be rearranged  

__Any lines of code that do not fall in between a opened and closed annotation will be treated as an individual tuple consisting of solely that line.__  

__NESTED ANNOTATION should not be done, a tuple cannot be nested inside of another tuple__

Comments that are written for problem generation __will not__ be included in the created problems.  



#### Example
An example of a properly annotated file:  
```
// {START
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
If this file is used to generate Parson's Problems using PPALMS, all generated problems will ave the same 5 first lines (line 2-6 in original code) and the same 2 last lines (line 14-15 in original code). The remaining lines which are not annotation will be shuffled around. However line 9 and 10 in the original code will always be together in that order. Line 12, 13 along with that line tuple will be shuffled around.  