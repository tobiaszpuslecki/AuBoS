// Automate boring stuff
// Helpful in SPOJ challenges

// TODO:
// -GUI
// -expections



#include "AuBoS.h"


int main(int argc, char const *argv[])
{
	configFile.open("config.txt");

	if (configFile.is_open())
	{
		loadConfig(config);
	}
	else
	{
		cout << "ERROR! Cannot open config file!";
		return -1;
	}

	
	compileFunc(config);
	runProgram(config);
	compareResults(config);




	configFile.close();
}


void loadConfig(cfg& config)
{
	string paramName;
	string param;
	char delimeter('=');

	while (! configFile.eof() )
    {
    	getline(configFile, paramName, delimeter);
		getline(configFile, param);

		switch(paramName[0])
		{
			case '1'         : config.path=param; break;
			case '2'         : config.name=param; break;
			case '3'         : config.compile=param; break;
			case '4'         : config.compile_param=param; break;
			case '5'         : config.in=param; break;
			case '6'         : config.out=param; break;
			case '7'         : config.truly=param; break;
			default: cout << "ERROR! Fault in parameters!";
		}
   	}



	/* config.txt example 
		1path=/Users/tobing/Desktop/LisaScript
		2name=test.cpp
		3compile=g++
		4compile_param=-o
		5in=in.txt
		6out=out.txt
		7truly=true.txt
	*/
	/*	
	cout << endl;
	cout << config.path << endl;
	cout << config.name << endl;
	cout << config.compile << endl;
	cout << config.compile_param << endl;
	cout << config.in << endl;
	cout << config.out << endl;
	cout << config.truly << endl;
	cout << endl;
	*/
}

void compileFunc(cfg& config)
{
	string terminalOrder;
	char terminalOrderChar[1024];
	terminalOrder+="g++ ";
	terminalOrder+=config.path;
	terminalOrder+='/';
	terminalOrder+=config.name;
	terminalOrder+=" ";
	terminalOrder+=config.compile_param;
	terminalOrder+=" ";
	terminalOrder+=config.path;
	terminalOrder+='/';
	terminalOrder+=config.name.substr(0,config.name.length()-4);

	//cout << endl << endl << terminalOrder << endl << endl;

	strcpy(terminalOrderChar, terminalOrder.c_str());

	system(terminalOrderChar);
}

void runProgram(cfg config)
{
	string terminalOrderCd = "cd " + config.path;
	string terminalOrder;
	char terminalOrderChar[1024];

	//terminalOrder+=config.path;
	//terminalOrder+='/';

	terminalOrder+="./";
	terminalOrder+=config.name.substr(0,config.name.length()-4);
	terminalOrder+=" < ";
	//terminalOrder+=config.path;
	//terminalOrder+='/';
	terminalOrder+=config.in;
	terminalOrder+=" > ";
	//terminalOrder+=config.path;
	//terminalOrder+='/';
	terminalOrder+=config.out;


	//./test < in.txt > out.txt
	//cout << endl << endl << terminalOrderCd << endl << endl;
	//cout << endl << endl << terminalOrder << endl << endl;

	//strcpy(terminalOrderChar, terminalOrderCd.c_str());
	//system(terminalOrderChar);
	

	strcpy(terminalOrderChar, terminalOrder.c_str());
	system(terminalOrderChar);
}

void compareResults(cfg config)
{
	ifstream out;
	ifstream truly;

	out.open(config.out);
	truly.open(config.truly);

	

	if ( !out.is_open())
	{
		cout << "ERROR! Cannot open out file!";
	}
	if ( !truly.is_open())
	{
		cout << "ERROR! Cannot open truly file!";
	}

	
	string outLine;
	string trulyLine;
	bool fail=false;

	while (! truly.eof() )
    {
    	getline(truly, trulyLine);
    	getline(out, outLine);
		

		if (outLine.compare(trulyLine) != 0)
		{
			fail=true;
			break;
		}
   	}

   
   	if (fail)
   	{
   		cout << endl << "###################";
   		cout << endl << "#";
   		cout << "\x1b[31;47m   TEST - FAIL   \x1b[0m";
   		cout << "#";
   		cout << endl << "###################";
   		cout << endl <<endl;
   	}
   	else
   	{
   		



   		cout << endl << "###################";
   		cout << endl << "#";
   		cout << "\x1b[34;47m    TEST - OK    \x1b[0m";
   		cout << "#";
   		cout << endl << "###################";
   		cout << endl <<endl;



   	}
}










