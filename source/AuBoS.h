#ifndef aubos_h
#define aubos_h


#include <iostream>
#include <fstream>

using namespace std;

ifstream configFile;


struct cfg
{
	string path;
	string name;
	string compile;
	string compile_param;
	string in;
	string out;
	string truly;
};
cfg config;



void loadConfig(cfg& config);
void compileFunc(cfg& config);
void runProgram(cfg config);
void compareResults(cfg config);


#endif