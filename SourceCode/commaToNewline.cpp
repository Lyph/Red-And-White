/*
#include <iostream> 
#include <string> 
#include <fstream> 
#include <iomanip> 
#include <iostream>
#include <stdlib.h> 
#include <bitset> 
#include <vector> 
#include <math.h> 
#include <algorithm> 
//#include "stdafx.h" //for Visual Studios 

using namespace std;

int main() {
	ofstream outFile("test.txt"); //where data is going
	ifstream file("Specialized School Original.csv");
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

	return 0;
}
*/