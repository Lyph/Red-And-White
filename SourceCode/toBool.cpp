/*
#include <iostream> 
#include <string> 
#include <fstream> 
#include <iomanip> 
#include <stdlib.h> 
#include <bitset> 
#include <vector> 
#include <math.h> 
#include <algorithm> 
//#include "stdafx.h" //for Visual Studios 

using namespace std; 

int converter() {
	vector<int> score;
	ofstream outFile("in.txt"); //where data is going
	ifstream file("inputBool.csv");

	string inLine;
	string outLine;
	int maxLength = 0;

	if (file.is_open())
	{
		getline(file, inLine);
		for (int i = 0; i < inLine.length(); i++) {
			if (inLine[i] == ',') {
				maxLength++;
			}
		}
		maxLength++;

		do {
			for (int i = 0; i < inLine.length(); i++) {
				if (inLine[i] == ',') {
					outLine += "\n";
				}
				else {
					outLine += inLine[i];
				}
			}
			outLine += "\n";
			outFile << outLine;
			outLine = "";
		}

		while (getline(file, inLine));

		file.close();
	}

	return maxLength;
}

int main()
{
	int max = converter();

	ofstream outFile("outputBool.csv"); //where data is going
	ifstream file("in.txt"); //where data is coming

	string inLine;
	string outLine;
	int count = 0;

	if (file.is_open())
	{
		
		for (int i = 0; i < max; i++) {
			getline(file, inLine);
			outLine += inLine + ",";
		}
		outLine += "\n";
		outFile << outLine;
		outLine = "";

		while (getline(file, inLine))
		{
			count++;
			if (inLine == "") {
				outLine += "0,";
			}
			else {
				int num = stoi(inLine);
				num = num % 2; //inverse
				outLine += to_string(num) + ",";
			}
			if (count == max) {
				outLine += "\n";
				outFile << outLine;
				outLine = "";
				count = 0;
			}
		}
		file.close();
		remove("in.txt");
	}

	return 0;
}
*/