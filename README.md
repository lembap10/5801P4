# PPALMS Software Version 0.1

## Project Overiew

This is version 0.1 of the PPALMS proect. This covers the annotation parsing portion of this application using the classes ParsedCode, Parser and DefaultCodeParser. The annotation it parses is described in annotation.md. Testing files are also included in this project, the files included are described below.

## Functionality of Version 0.1 main

This first version of PPALMS simply takes in the name of a file of source code and prints out a parsed version of this file. This will allow for the easy creation of questions when implemented in later versions.

## File Overview

This section described the overall file structure for this project.  
The main folders:

- /include : holds relevant header files
- /src : include the code for each class
- /srcFiles : folder to store files to run code with (test files for testing)
- /testing : includes all files for testing
  - one file per each member's test
  - file to run all tests at once
  - tester.cpp holds the function used to test (compares two void pointers to check if equal)

Other relevant files:

- main.cpp holds the code to run the created classes / see what current part of PPALMS works
- annotation.md describes the expected format for annotation of source code files

## Running the code

In order to run the code, g++ must be functioning on the machine this gets compiled on.  
To run, first compile using g++ :

```
g++ -o ppalms main.cpp include/ParsedCode.h include/DefaultCodeParser.h include/Parser.h include/Params.h include/UserInterface.h src/DefaultCodeParser.cc src/ParsedCode.cc src/Params.cc src/UserInterface.cc include/JSONGenerator.h src/JSONGenerator.cc src/FillInBlanksGenerator.cc include/FillInBlanksGenerator.h src/MCGenerator.cc include/MCGenerator.h
```

_must be in the 5801P4 dir to run such command_

Then, run:

```
./ppalms
```

_for now executes whatever is in main_

This will request the name of a file to parse. This file should be present in the srcFiles folder. Do not worry about showing the proper path, simply add the file name. This will then print the parsedcode representation of that given code file.

## Run Tests

```
g++ -o tests testing/* include/* src/*
```

This will run the set of tests that have been made and which are described in the PPALMS Test Case Report document.

### Conditions to parse code

- The source code should be place in the srcFiles directory
