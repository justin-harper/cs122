/* Basic-one program
Programmer William York
Reads a set of 4 digit machine language instructions and performs a memory dump
April 1, 2012 */



#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

//declare constants

const int	READ = 33,
WRITE = 32,
LOAD = 31,
STORE = 30,
ADD = 21,
SUBTRACT = 20,
DIVIDE = 11,
MULTIPLY = 10,
BRANCH = 43,
BRANCHNEG = 42,
BRANCHPOS = 41,
BRANCHZERO = 40,
HALT = 50;

class Basic_one
{
private:
	int accumulator,
		programCounter,
		operationCode,
		operand,
		instructionRegister,
		size,
		memory[100];


public:
	Basic_one();
	void loadMemory();
	void displayMemory();
	void execute();
};

//declare function prototypes

void titleFunc(void);


//default constructor
Basic_one::Basic_one()
{
	//Initialize private members
	accumulator = 0;
	programCounter = 0;
	instructionRegister = 0;
	operationCode = 0;
	operand = 0;
	size = 0;

}

int main()
{
	Basic_one computerDump;
	titleFunc();
	computerDump.loadMemory();
	computerDump.execute();

	return 0;
}

void titleFunc()
{
	cout << "\n\n";
	cout << " Welcome to my basic-one program \n\n";
	cout << " \n\n";
}

void Basic_one::loadMemory()
{
	ifstream file;
	string fileName;

	cout << "\n\n";
	cout << " Enter file name here: ";
	cin >> fileName;
	cout << "\n\n";

	for (int i = 0; i < 100; i++)
	{
		memory[i] = 0;
	}

	file.open(fileName);
	cout << "\n\n";




	if (file.is_open())
	{
		size = 0;

		cout << " Here is the list of the operation code \n";
		cout << " on the file: \n\n\n";
		cout << " \n\n";
		cout << " Operation codes:          Opoerands: \n";

		while (file >> instructionRegister)
		{


			memory[size] = instructionRegister;


			operationCode = instructionRegister / 100;
			operand = instructionRegister % 100;


			cout << "  " << operationCode << "                            " << operand << endl;
			size++;
		}

		cout << "\n\n";
		cout << " Please confirm this is the data You have requested . \n\n";
	}




	file.close();


	system("PAUSE");
}

void Basic_one::displayMemory()
{
	ifstream file;
	string fileName;




	system("cls");



	cout << "\n\n";
	cout << " Registers: \n\n";
	if (accumulator >= 0)
	{
		cout << " Accumulator              +" << setfill('0') << setw(4) << accumulator << "\n\n";
	}
	else if (accumulator < 0)
	{
		cout << " Accumulator              -" << setfill('0') << setw(4) << (accumulator * (-1)) << "\n\n";
	}
	cout << " Prog_counter              " << setw(2) << programCounter << "\n\n";
	cout << " Instructionregister      +" << setw(4) << memory[programCounter] << "\n\n";
	cout << " Operationcode             " << setw(2) << operationCode << "\n\n";
	cout << " Operand                   " << setw(2) << operand << "\n\n\n\n";
	cout << " MEMORY: " << "\n\n\n";
	cout << setfill(' ') << setw(12) << "0" << setw(7) << "1" << setw(7) << "2" << setw(7) << "3" << setw(7) << "4" << setw(7) << "5" << setw(7) << "6" << setw(7) << "7" << setw(7) << "8" << setw(7) << "9" << "\n\n\n";


	for (int x = 0; x < 100; x += 10)
	{
		cout << " " << setw(4) << x << "   ";

		for (int y = x; y < x + 10; y++)
		{

			if (memory[y] >= 0)
			{
				cout << " +" << setfill('0') << setw(4) << memory[y] << " " << setfill(' ');
			}
			else if (memory[y] < 0)
			{
				cout << " -" << setfill('0') << setw(4) << (memory[y] * (-1)) << " " << setfill(' ');
			}

		}
		cout << "\n\n";
	}
}

void Basic_one::execute()
{
	programCounter = 0;

	do
	{


		instructionRegister = memory[programCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		displayMemory();


		switch (operationCode)
		{
		case READ:
			cout << "\n\n";
			cout << " Enter an integer: ";
			cin >> memory[operand];
			cout << "\n\n";
			programCounter++;
			break;
		case WRITE:
			cout << "\n";
			cout << " Result: " << memory[operand] << "\n\n";
			programCounter++;
			break;
		case LOAD:
			accumulator = memory[operand];
			programCounter++;
			break;
		case STORE:
			memory[operand] = accumulator;
			programCounter++;
			break;
		case ADD:
			accumulator += memory[operand];
			programCounter++;
			break;
		case SUBTRACT:
			accumulator -= memory[operand];
			programCounter++;
			break;
		case MULTIPLY:
			accumulator *= memory[operand];
			programCounter++;
			break;
		case DIVIDE:
			if (memory[operand] == 0)
			{
				cout << " Cannot divide by zero \n";
				exit(1);
				break;
			}
			accumulator /= memory[operand];
			programCounter++;
			break;
		case BRANCH:
			programCounter = operand;
			programCounter++;
			break;
		case BRANCHNEG:
			if (accumulator < 0)
			{
				programCounter = operand;
			}
			programCounter++;
			break;
		case BRANCHPOS:
			if (accumulator > 0)
			{
				programCounter = operand;
			}
			programCounter++;
			break;
		case BRANCHZERO:
			if (accumulator == 0)
			{
				programCounter = operand;
			}
			programCounter++;
			break;
		case HALT:
			accumulator = 0;
			operationCode = 0;
			operand = 0;

			cout << " Program Halted \n\n";
			exit(0);
			break;
		default:
			cout << " Error! Invalid instruction \n\n";
			exit(1);
			break;
		}



		ofstream outputFile;




		outputFile.open("output.txt");

		if (!outputFile)
		{
			cout << " Error with file! \n";
		}
		outputFile << " Registers: \n\n";
		if (accumulator >= 0)
		{
			outputFile << " Accumulator              +" << setfill('0') << setw(4) << accumulator << "\n\n";
		}
		else if (accumulator < 0)
		{
			outputFile << " Accumulator              -" << setfill('0') << setw(4) << (accumulator * (-1)) << "\n\n";
		}
		outputFile << " Prog_counter                " << setw(2) << programCounter << "\n\n";
		outputFile << " Instructionregister      +" << setw(4) << memory[programCounter] << "\n\n";
		outputFile << " Operationcode               " << setw(2) << operationCode << "\n\n";
		outputFile << " Operand                     " << setw(2) << operand << "\n\n\n\n";
		outputFile << " MEMORY: " << "\n\n\n";
		outputFile << setfill(' ') << setw(12) << "0" << setw(7) << "1" << setw(7) << "2" << setw(7) << "3" << setw(7) << "4" << setw(7) << "5" << setw(7) << "6" << setw(7) << "7" << setw(7) << "8" << setw(7) << "9" << "\n\n\n";


		for (int x = 0; x < 100; x += 10)
		{
			outputFile << " " << setw(4) << x << "   ";

			for (int y = x; y < x + 10; y++)
			{

				if (memory[y] >= 0)
				{
					outputFile << " +" << setfill('0') << setw(4) << memory[y] << " " << setfill(' ');
				}
				else if (memory[y] < 0)
				{
					outputFile << " -" << setfill('0') << setw(4) << (memory[y] * (-1)) << " " << setfill(' ');
				}

			}
			outputFile << "\n\n";
		}

		outputFile.close();

	} while (operationCode != HALT);






}
