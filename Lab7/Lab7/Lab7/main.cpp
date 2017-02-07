#include "SimpleImageEffect.h"
#include "Point.h"
#include "RemoveGreenEffect.h"
#include "StringSplitter.h"

#include <fstream>
#include <iostream>


using namespace std;

int main(void)
{
	ifstream infile("bunny.ppm");
	ofstream outfile("test2.ppm");

	vector<Point> points{};
	string line = "";

	StringSplitter split{};
	vector<string> temp;


	//the first three lines of the outfile should be the same
	getline(infile, line);
	outfile << line << endl;

	getline(infile, line);
	outfile << line << endl;

	getline(infile, line);
	outfile << line << endl;


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
	RemoveGreenEffect rGreen{};

	rGreen.processImage(points);



	for (int i = 0; i < points.size(); i++)
	{


		outfile << points[i].toString() << endl;
	}





	return 0;
}