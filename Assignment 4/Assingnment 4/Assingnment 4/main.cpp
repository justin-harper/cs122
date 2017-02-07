/*
Assignment: 4

Description: Paycheck Calculator

Author: Justin Harper
WSU ID: 10696738 Completion Time: 4hrs

In completing this program, I received help from the following people:
myself

version 1.0 (major relese) I am happy with this version! 
*/


#pragma region Includes

#include "SimpleImageEffect.h"
#include "Point.h"
#include "StringSplitter.h"

#include "RemoveRedEffect.h"
#include "RemoveGreenEffect.h"
#include "RemoveBlueEffect.h"

#include "NegateRed.h"
#include "NegateGreen.h"
#include "NegateBlue.h"

#include "AddRandomNoise.h"
#include "HighContrast.h"
#include "GreyScale.h"

#include "FlipHorzantal.h"

#include "userInterface.h"



#include <fstream>
#include <iostream>


#include <Windows.h>


#pragma endregion

using namespace std;

int main(void)
{

	//print out welcome message
	cout << "Hello!" << endl << "Welcome to the simple image processor" << endl
		<< "who needs instagram anyway?" << endl << endl;

	

#pragma region openFIle and store in vector

	//some initialization variables
	string in = "bunny.ppm";
	string out = "output.ppm";

	ifstream infile("bunny.ppm");
	ofstream outfile("output.ppm");

	vector<Point> points{};
	string line = "";

	StringSplitter split{};
	vector<string> temp;
	cout << "Opening file for proccessing" << endl
		<< "working..." << endl;

	//the first three lines of the outfile should be the same as the input file
	getline(infile, line);
	outfile << line << endl;

	getline(infile, line);
	outfile << line << endl;
	int px1 = stoi(line);

	getline(infile, line);
	outfile << line << endl;
	int px2 = stoi(line);

	//fill vector with "points" (pixles) form the file
	//note the points vector will be quite large
	while (getline(infile, line))
	{
		temp = split.split(line, " ");
		Point Temp1{ stoi(temp[0]), stoi(temp[1]), stoi(temp[2]) };
		Point Temp2{ stoi(temp[3]), stoi(temp[4]), stoi(temp[5]) };
		Point Temp3{ stoi(temp[6]), stoi(temp[7]), stoi(temp[8]) };
		Point Temp4{ stoi(temp[9]), stoi(temp[10]), stoi(temp[11]) };
		Point Temp5{ stoi(temp[12]), stoi(temp[13]), stoi(temp[14]) };

		points.push_back(Temp1);
		points.push_back(Temp2);
		points.push_back(Temp3);
		points.push_back(Temp4);
		points.push_back(Temp5);

	}
	//we are done with the input file
	infile.close();
	cout << "Done!" << endl;
	
	system("pause");
	
	system("cls");

	
#pragma endregion
	


#pragma region Image Effects

	//instantiate the image processors
	RemoveRedEffect		rRed{};
	RemoveGreenEffect	rGreen{};
	RemoveBlueEffect	rBlue{};

	NegateRed	nRed{};
	NegateGreen nGreen{};
	NegateBlue	nBlue{};

	AddRandomNoise	randNoise{};
	HighContrast	Highc{};
	GreyScale		Greys{};

	FlipHorzantal	flipH{};

	



#pragma endregion

#pragma region Process Image

	//get user input as to what effects to process
	//basicly a big switch statement
	int userInput = 0;
	bool chain = true;




	while (chain) //loop until user selects exit
	{

		//using a try catch because this opperation is not "garenteed"

		try
		{
			userInput = userInterface();
		}
		catch (...)
		{
			cout << "error" << endl;
			return 0;
		}

		switch (userInput)
		{
			case 1:	cout << "removing red" << endl;
				rRed.processImage(points);
				Sleep(1000); //sleep for 3 seconds
				break;
			case 2:	cout << "removing green" << endl;
				rGreen.processImage(points);
				Sleep(1000);
				break;
			case 3:	cout << "removing blue" << endl;
				rBlue.processImage(points);
				Sleep(1000);
				break;
			case 4:	cout << "negating red" << endl;
				nRed.processImage(points);
				Sleep(1000);
				break;
			case 5:	cout << "negating green" << endl;
				nGreen.processImage(points);
				Sleep(1000);
				break;
			case 6:	cout << "negating blue" << endl;
				nBlue.processImage(points);
				Sleep(1000);
				break;
			case 7:	cout << "adding random noise" << endl;
				randNoise.processImage(points);
				Sleep(1000);
				break;
			case 8:	cout << "converting to greyscale" << endl;
				Greys.processImage(points);
				Sleep(1000);
				break;
			case 9:	cout << "converting to high contrast" << endl;
				Highc.processImage(points);
				Sleep(1000);
				break;
			case 10: cout << "fliping image horizantaly" << endl;
				flipH.processImage(points);
				break;
			case 11: cout << "fliping image vertiacly" << endl;
				//flipV.processImage(points, px1, px2);
				break;
			case 12: chain = false;
				break;

		}
		

		system("cls");

	}

#pragma endregion

#pragma region Output to file 

	//after image has been processed output points ("pixles") to file

	for (int i = 0; i < points.size(); i++)
	{	//note points vector is quite large
		outfile << points[i].toString() << endl;
	}


#pragma endregion



	
	//close the output file 
	outfile.close();

	

	//opens the file for viewing if you have a program that can read .ppm
	//note this is windows only
	system(out.c_str()); 
	
	return 0;
}

