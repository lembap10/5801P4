# PPALMS Software Version 0.0 

## Project Overiew  


## File Overview  
This section described the overall file structure for this project.  
The main folders:
- /include : holds relevant header files  
- /src : include the code for each class
- /srcFiles : folder to store files to run code with (test files for testing)   
- /testing : includes all files for testing
    - one file per each member's test
    - tester.cpp holds the function used to test (compares two void pointers to check if equal)  
  
Other relevant files:
- main.cpp holds the code to run the created classes / see what current part of PPALMS works
- annotation.md describes the expected format for annotation of source code files
- 

## Running the code
To run, first compile :  
```  
g++ -o ppalms main.cpp include/ParsedCode.h include/DefaultCodeParser.h include/Parser.h src/DefaultCodeParser.cc src/ParsedCode.cc
```  
*must be in the 5801P4 dir to run such command*  

Then, run:
```
./ppalms
```
_for now executes whatever is in main_

## Run Tests  

```
g++ -o tests testing/* include/* src/*
```

### Conditions to parse code  
 - The source code should be place in the srcFiles directory  

