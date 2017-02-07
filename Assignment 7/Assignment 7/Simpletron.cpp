/***************************************************************
* Programmer: Justin Harper                                    *
* Class: Cpt S 122, Spring 2014;			                   *
* Programming Assignment: pa7                                  *
* Description: Simpletron									   *
****************************************************************/
#include "SIMPLETRON.h"




SIMPLETRON::SIMPLETRON()
{
	
	for(int j = 0; j < 1000; j++)
	memory[j] = 0;
	accumulator = 0;
	instructionCounter = 0;
	instructionRegister = 0;
	opCode = 0;
	opeRand = 0;
}


SIMPLETRON::~SIMPLETRON()
{

}


void instruction()
{
	cout<<"*** Welcome to Simpletron! **"<<endl;
	cout<<"*** Please enter your program one instruction ***"<<endl;
	cout<<"*** (or data word) at a time. I will type the ***"<<endl;
	cout<<"*** location number and a question mark (?).  ***"<<endl;
	cout<<"*** You then type the word for that location. ***"<<endl;
	cout<<"*** Type the sentinel -99999 to stop entering ***"<<endl;
	cout<<"*** your program. ***"<<endl;
}



bool fileExist(string inFile)
{

	ifstream Simpletron;
	
	//opens file for read 
	Simpletron.open(inFile.c_str(), ifstream::in);

	if (Simpletron.good())
	{
		//close's the file
		Simpletron.close();
		return true;
	}
	else 
	{
		return false;
	}
}



void SIMPLETRON::displayMemory()
{
	//int memory[1000];
	int mSize = 0;
	ifstream Simpletron;
	string inFile;
	//int output = 0;

	//prompts user to enter the name of the file after the file has been succesfully
	//executed
	cout<<"\nPlease Enter the name of the file: "<<endl;
	cin>>inFile;
	cout<<"\nRegisters: "<<endl;
	cout<<"Accumulator   \t";

	if(accumulator < 10)
	{
		cout<< "000";
	}
	else if(accumulator < 1000 && accumulator > 9)
	{
		cout<<"00";
	}
	else if(accumulator <= 9999 && accumulator >999)
	{
		cout<<"0";
	}
	cout<< accumulator <<endl;

	cout << "InstructionCounter \t";

	if (instructionCounter < 10)
		cout<< "0";
		cout<< instructionCounter << endl;
		cout<< "instructionRegister \t";
		if (instructionRegister < 10)
		{
			cout << "000";
		}
		else if (instructionRegister < 1000 && instructionRegister > 9)
		{
			cout<< "00";
		}
		else if(instructionRegister <= 9999 && instructionRegister > 999)
		{
			cout<< "0";
		}
		
		cout<< instructionRegister <<endl;
		cout<< "OpCode  \t";

		if (opCode < 10)
		
		cout << "0";
		cout << opCode << endl;
		cout << "OpeRand   \t";

	    if(opeRand < 10)
			cout << "0";
		cout <<opeRand << endl;
		cout << "\nMemory: "<< endl<<endl;
		Simpletron.open(inFile.c_str(), ifstream::in);

		//streams each and every memory local to this function with instruction register
		Simpletron >> instructionRegister;
		
		//checks to see if the variable name simpletron is not at the end of file
		//and then performs the tasks inside the while loop
		while (!Simpletron.eof())
		{

			memory[mSize] = instructionRegister;
			//streams each and every memory local to this function with instruction register
			Simpletron>> instructionRegister;

			//sets the width to five
			cout << setw(5) << memory[mSize] << setw(5);
			cout << endl;
			mSize++;
		}
		//print function for ten rows and coloums
		cout <<" ";
		for(int i = 0; i<10; i++)
		{
			printf("     %d", i);
			//cout<< i <<"\t";
		}
			cout<<endl;
		for(int i = 0; i < 10; i++)
		{//using printf because it is easier to get the formatted output
			printf("%5d", i * 10);
			//cout << i*10 <<"\t";

			for(int j = 0; j< 10; j++)
			{
				printf("%+5d", memory[j + i*10]);

				//cout<< memory[j + i*10] <<"\t";
			}
			cout<< endl;
		}
		//closes display memory file
		Simpletron.close();
}



void SIMPLETRON::loadMemory()
{
	//reads file name simpletron
	ifstream Simpletron;

	//stores file
	string inFile;
	//int memory[1000];
	int instruction;

	accumulator = 0;
	instructionCounter = 0;
	instructionRegister = 0;
	opCode = 0;
	opeRand = 0;
	cout<<"\nPlease enter the name of the file: "<<endl;
	cin>> inFile;
	
	//opens the file
	Simpletron.open(inFile.c_str(), ifstream::in);
	int size = 0;

	//when file is succesfully open it then diplays the file	
	if(Simpletron)
	{
		cout<<"\n The instruction that are contain in the file " << inFile << " are as follow: "<<endl;
		Simpletron >> instruction;
		//reads file till it ends
		while (!Simpletron.eof())
		{
			memory[size] = instruction;
			Simpletron >> instruction;
			cout << setw(5) << memory[size] << setw(5)<<endl;
			size++;
		}
			cout<< "\nThe Information in the file has been Read." << endl;
	}
	//this signal file was not successfully open
	else if(Simpletron.fail())
	{
		cout << "\nThe file could not be open hence it does not exist:"<< endl;

	}
	//closses file
	Simpletron.close();
}
void SIMPLETRON::execute()
{
		displayMemory();
	
	do
	{
		//fetch the contents of location in memory
		instructionRegister = memory[instructionCounter];
		cout << instructionRegister << endl;
		//opcode is extracted from the instruction register
		opCode = instructionRegister / 100;
		cout<< opCode <<endl;
		//opeRand is extracted from the instruction register
		opeRand = instructionRegister % 100;
		cout<< opeRand <<endl;
		//increments at the end of each execution
		instructionCounter++;
	
		//this is where the behavior of various SML instructions determine.
		switch(opCode)
		{
			case READ:
				cout << "Please Enter an integer value: " << endl;
				cin >> memory[opeRand];
				system("pause");
			break;
			case WRITE:
				cout << memory[opeRand] << endl;
				system("pause");
			break;
			case LOAD:
				accumulator = memory[opeRand];
				system("pause");
			break;
			case STORE:
				memory[opeRand] = accumulator;
				system("pause");
			break;
			case ADD:
				accumulator += memory[opeRand];
				system("pause");
			break;
			case SUBTRACT:
				accumulator -= memory[opeRand];
				system("pause");
			break;
			case MULTIPLY:
				accumulator *= memory[opeRand];
				system("pause");
			break;
			case DIVIDE:
				if (memory[opeRand] == 0)
				{
					cout << "*** Attempt to divide by zero ****" << endl;
					cout << "*** cause Simpletron execution to be terminated ***" << endl;
					exit(1);
					break;
				}
				accumulator /= memory[opeRand];
				system("pause");
				//instructionCounter++;

			break;
			case MOD:
				if(memory[opeRand] == 0)
				{
					cout<< "*** Attempt to mod by zero ****" << endl;
					cout << "*** cause Simpletron execution to be terminated ***" << endl;
					exit(1);
					break;
				}
				accumulator %= memory[opeRand];
				system("pause");
				break;
				//still working progress
			case EXPONENTIAL:
				accumulator = pow((double)accumulator, memory[opeRand]);
				
				system("pause");
				break;

			case BRANCH:
				instructionCounter = opeRand;
				system("pause");
				//instructionCounter++;
			break;
			case BRANCHNEG:
				if(accumulator < 0)
					instructionCounter = opeRand;
				system("pause");
				//instructionCounter++;
			break;
			case BRANCHZERO:
				if(accumulator == 0)
					instructionCounter = opeRand;
				system("pause");
				//instructionCounter++;
			break;
			case HALT:
				cout << "\n*** Simpletron execution is terminated ***" << endl;
				//system ("pause");
				exit (0);
			break;
			default:
				cout << "\nERROR: Invalid SML instruction -- Program terminating" << endl;
				//system ("pause");
				exit (1);
			break;
		}
		// end of  the For

	}while (instructionRegister != HALT && instructionRegister != 1);

}

			
