#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main(){
	
	string infile = "";
	cout << "***SML Code Commenter***" << endl;
	cout << "Enter the name of the input file: ";
	cin >> infile;

	ifstream input(infile);
	ofstream output("sampleout.txt");

	int number;
	int num;
	int operation;
	string line;
	input >> number;
	while (getline(input, line)){
		
		num = number % 100;

		operation = number / 100;


		if (operation == 10){
			output << number << "  #Read a word from keyboard into " << setfill('0') << setw(2) << num << endl;
		}
		else if (operation == 11){
			output << number << "  #Write a value at " << setw(2) << num << " to screen" << endl;
		}
		else if (operation == 20){
			output << number << "  #Load value at " << setw(2) << num << " into accumulator" << endl;
		}
		else if (operation == 21){
			output << number << "  #Store accumulator value into address " << setw(2) << num << endl;
		}
		else if (operation == 30){
			output << number << "  #Add value at " << setw(2) << num << " into accumulator" << endl;
		}
		else if (operation == 31){
			output << number << "  #Subtract value at " << setw(2) << num << " from accumulator" << endl;
		}
		else if (operation == 32){
			output << number << "  #Divide value at " << setw(2) << num << " with accumulator" << endl;
		}
		else if (operation == 33){
			output << number << "  #Multiply value at " << setw(2) << num << " into accumulator" << endl;
		}
		else if (operation == 40){
			output << number << "  #Branch to location " << setw(2) << num << endl;
		}
		else if (operation == 41){
			output << number << "  #If accumulator is negative, branch to location " << setw(2) << num << endl;
		}
		else if (operation == 42){
			output << number << "  #If accumulator is zero, branch to location " << setw(2) << num << endl;
		}
		else if (operation == 43){
			output << number << "  #Halt the program " << setw(2) << num << endl;
		}
		else if (operation == 00){
			output <<setfill('0')<< setw(4)<< number << "  #NULL operation" << endl;
		}
		else{
			output << number << "  #Unknown operation" << endl;
		}
		input >> number;
	}



	return 0;
}