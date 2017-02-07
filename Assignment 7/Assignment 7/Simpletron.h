/***************************************************************
* Programmer: Justin Harper                                    *
* Class: Cpt S 122, Spring 2014;			                   *
* Programming Assignment: pa7                                  *
* Description: Simpletron									   *
****************************************************************/
#ifndef SIMPLETRON_H
#define SIMPLETRON_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>
#include <cstdlib>

using namespace std;
//using #define constants seems like an easy way to handle the commands
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define MOD 34
#define EXPONENTIAL 35
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

class SIMPLETRON
{
	
public:
	//constructor
	SIMPLETRON();

	//destructor
	~SIMPLETRON();

	//public memeber fuctions
	void loadMemory();
	void displayMemory();
	void execute();
	bool fileExist(string inFile);
	
private:
	//private members
	int accumulator;
	int instructionCounter;
	int opCode;
	int opeRand;
	int instructionRegister;
	int memory[1000];
};
//shows the user the instructions
void instruction();

#endif

	
