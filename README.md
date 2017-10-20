# AuBoS
// Automate boring stuff
// Helpful in SPOJ challenges

macOS ver. 1.0

1. Configure config.txt file (*).
2. Put all files to AuBoS directory ( *.cpp, in, truly)
3. Run Terminal
4. Select localization (using cd command) 
5. Write ./AuBoS


-----------------------------------------------------------------
(*)Config file:
1path           - where are the files which will be tested 
2name           - name of cpp file (source code)
3compile        - compilator name
4compile_param  - parameters for compilator
5in             - input file name    (input data)
6out            - output file name (output data)
7correct          - File with the correct answers (data to compare with output data)



Example:


1path=/Users/tobing/Desktop/AuBoS
2name=test.cpp
3compile=g++
4compile_param=-o
5in=input.txt
6out=out.txt
7correct=true.txt



