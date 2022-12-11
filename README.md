# PPALMS Software Version 0.2

## Project Overiew

This is version 0.2 of the PPALMS project. This version of the PPALMS project builds off of what version 1 was with additional functionality. New classes created include JsonGenerator, MCGenerator, FillInBlanksGenerator, Controller, Params, and UserInterface. The purpose of version 0.2 is to supply a json file containing user specifications of the attributes of desired questions to be generated. The json file is to be given to a supplier problem generator which will generate the file.

## Functionality of Version 0.2 main

This second version of PPALMS simply takes in the name of a file of source code, number of students to generate variants, question type, intendedLMS, and indended quiz file type. Using this information, it will create a json file with the information inside. Different question types, like fill in the blank or multiple choice, will have unique attributes inside the json file. For fill in the blank, the file will have an exculusive length of blanks attribute. For multiple choice, the file will have a exculusive number of choices attribute. The json file is created under the /json directory inside 5801P5 directory. This will allow for the easy creation of questions when supplied to the supplier problem generator.

## File Overview

This section described the overall file structure for this project.  
The main folders:

- /include : holds relevant header files
- /json : this is where all output json files are held
- /src : include the code for each class
- /srcFiles : folder to store files to run code with (test files for testing)
- /testing : includes all files for testing
  - one file per each member's test
  - file to run all tests at once
  - tester.cpp holds the function used to test (compares two void pointers to check if equal)

Other relevant files:

- main.cpp runs code to create json file
- annotation.md describes the expected format for annotation of source code files

## Running the code

In order to run the code, g++ must be functioning on the machine this gets compiled on.  
To run, first compile using g++ :

```
g++ -o ppalms main.cpp include/ParsedCode.h include/DefaultCodeParser.h include/Parser.h include/Params.h include/UserInterface.h src/DefaultCodeParser.cc src/ParsedCode.cc src/Params.cc src/UserInterface.cc include/JSONGenerator.h src/JSONGenerator.cc src/FillInBlanksGenerator.cc include/FillInBlanksGenerator.h src/MCGenerator.cc include/MCGenerator.h include/Controller.h src/Controller.cc
```

_must be in the 5801P5 dir to run such command_

Then, run:

```
./ppalms
```

_for now executes whatever is in main_

This will run the program and request:

-Enter the number of students: 
-Enter the question type (MC [Multiple Choice] or FB [Fill in the Blank]): 
-Enter the intended LMS (canvas, blackboard, or moodle):
-Enter the intended quiz format (qti or gift):
-Enter the name of the file (stored in srcFiles directory) to be parsed:


Answering all fields adequately will allow for a json file to be outputted. 
The json file will have attributes:

-"numStudents": number of variations to generate
-"questionType": Type of Question. Will be set to multiple choice.
-"intendedLMS": 3 options: canvas, moodle, blackboard
-"intendedQuizType": 2 options: .gift, .qti

Multiple Choice exclusive:
-"numChoices": number of choices

Fill in the blank exclusive:
-"blankLength": desired length of blank 


## Run Tests

```
g++ -o tests testing/* include/* src/*
```

*Youfu

### Conditions to parse code

- The source code should be place in the srcFiles directory
