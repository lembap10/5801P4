# PPALMS Software Annotation Standard  

The following is how to annotate files of source code such that the PPALMS system can properly parse it. This includes the exlusion, and grouping of lines in the original code.

This document describing the annotation works with various source code file types. The allowed files are: .cpp, .c, .cs, .cc, .h, .java, .py, .js

The value <comment_symbol> will represent the characters needed to start a comment in various lamguages.  
These are:
- "//" for .cpp, .c, .cs, .cc, .h, .js, .java  
- "#" for .py  