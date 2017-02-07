#include "Point.h"
#include "StringSplitter.h"
#include "GreenScreenEffect.h"
#include "SimpleImageEffect.h"

#include <iostream>
#include <fstream>


using namespace std;
int main(void)
{
	ifstream target_file("bunny.ppm");
	ifstream key_file("smiley.ppm");
	ofstream final_file("output.ppm");
	Point keyColor{ 0, 0, 0 };

	StringSplitter split{};
	string line1 = "";
	string line2 = "";
	vector<string> tempFile1;
	vector<string> tempFile2;

	vector<Point> targetFile;
	vector<Point> keyFile;

	getline(target_file, line1);
	getline(key_file, line2);
	final_file << line1 << endl;

	getline(target_file, line1);
	getline(key_file, line2);
	final_file << line1 << endl;

	getline(target_file, line1);
	getline(key_file, line2);
	final_file << line1 << endl;

	getline(key_file, line2);
	tempFile2 = split.split(line2, " ");

	keyColor.setRed(stoi(tempFile2[0]));
	keyColor.setGreen(stoi(tempFile2[1]));
	keyColor.setBlue(stoi(tempFile2[2]));

	cout << "key: "<< endl;
	cout << "red: "<< keyColor.getRed() << endl;
	cout << "green: "<< keyColor.getGreen() << endl;
	cout << "blue: "<< keyColor.getBlue() << endl;

	system("pause");

	key_file.seekg(0);
	getline(key_file, line2);
	getline(key_file, line2);
	getline(key_file, line2);


	
	while (getline(target_file, line1))
	{
		getline(key_file, line2);
		tempFile1 = split.split(line1, " ");
		tempFile2 = split.split(line2, " ");

		Point TempFile1_1{ stoi(tempFile1[0]), stoi(tempFile1[1]), stoi(tempFile1[2]) };
		Point TempFile1_2{ stoi(tempFile1[3]), stoi(tempFile1[4]), stoi(tempFile1[5]) };
		Point TempFile1_3{ stoi(tempFile1[6]), stoi(tempFile1[7]), stoi(tempFile1[8]) };
		Point TempFile1_4{ stoi(tempFile1[9]), stoi(tempFile1[10]), stoi(tempFile1[11]) };
		Point TempFile1_5{ stoi(tempFile1[12]), stoi(tempFile1[13]), stoi(tempFile1[14]) };

		Point TempFile2_1{ stoi(tempFile2[0]), stoi(tempFile2[1]), stoi(tempFile2[2]) };
		Point TempFile2_2{ stoi(tempFile2[3]), stoi(tempFile2[4]), stoi(tempFile2[5]) };
		Point TempFile2_3{ stoi(tempFile2[6]), stoi(tempFile2[7]), stoi(tempFile2[8]) };
		Point TempFile2_4{ stoi(tempFile2[9]), stoi(tempFile2[10]), stoi(tempFile2[11]) };
		Point TempFile2_5{ stoi(tempFile2[12]), stoi(tempFile2[13]), stoi(tempFile2[14]) };

		targetFile.push_back(TempFile1_1);
		targetFile.push_back(TempFile1_2);
		targetFile.push_back(TempFile1_3);
		targetFile.push_back(TempFile1_4);
		targetFile.push_back(TempFile1_5);

		keyFile.push_back(TempFile2_1);
		keyFile.push_back(TempFile2_2);
		keyFile.push_back(TempFile2_3);
		keyFile.push_back(TempFile2_4);
		keyFile.push_back(TempFile2_5);

	}

	GreenScreenEffect gse{};

	gse.processImage(targetFile, keyFile, keyColor);

	for (int i = 0; i < targetFile.size(); i++)
	{
		final_file << targetFile[i].toString() << endl;
	}







	return 0;
}