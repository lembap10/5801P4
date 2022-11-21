# PPALMS Software Version 0.0 

## File Overview  
This section described the overall file structure for this project.  
The main folders:
- /include : holds relevant header files


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

