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

bool zeroChecker = false;

int max() {
	ifstream file("inputMost.csv");

	string inLine;
	string inScore;
	int maxLength = 0;

	if (file.is_open())
	{
		while (getline(file, inLine)) {
			int i = 0;
			while (inLine[i] != ',') {
				i++;
			}
			i++;
			for (i;i < inLine.length();i++) {
				inScore += inLine[i];
			}
			int num = stoi(inScore);
			if (num == 0) { zeroChecker = true; }
			if (maxLength < num) { maxLength = num; }
			inScore = "";
		}
		file.close();
	}

	return maxLength;
}

struct lineObject {
	string area;
	vector<int> val;
	int total;
	lineObject(string a, vector<int> b, int tot) {
		area = a;
		val = b;
		total = tot;
	}

};


int main()
{
	int amt = max();
	if (zeroChecker == true) { amt++; }
	vector<int> temp;
	for (int i = 0; i < amt; i++) {
		temp.push_back(0);
	}
	vector<lineObject> test;
	ofstream outFile("outputMost.csv");
	ifstream file("inputMost.csv");
	string outLine;
	string inLine;
	string oldString;


	if (file.is_open())
	{
		vector<int> values = temp;
		int totalAmt = 0;
		string currString;
		string currInt;

		//firstline
		getline(file, inLine);
		int j = 0;
		while (inLine[j] != ',') {
			oldString += inLine[j];
			j++;
		}
		j++;
		for (j;j < inLine.length();j++) {
			currInt += inLine[j];
		}
		int num = stoi(currInt);
		if (zeroChecker == true) {
			values[num]++;
		}
		else {
			values[num - 1]++;
		}
		totalAmt++;
		currInt = "";


		while (getline(file, inLine))
		{

			int i = 0;
			while (inLine[i] != ',') {
				currString += inLine[i];
				i++;
			}
			i++;
			if (currString != oldString) {
				lineObject a(oldString, values, totalAmt); //this is after everything is done
				test.push_back(a);
				totalAmt = 0;
				values = temp;
				oldString = currString;
			}
			for (i;i < inLine.length();i++) {
				currInt += inLine[i];
			}
			int num = stoi(currInt);
			if (zeroChecker == true) {
				values[num]++;
			}
			else {
				values[num - 1]++;
			}
			totalAmt++;
			currString = "";
			currInt = "";
		}
		file.close();
		lineObject a(oldString, values, totalAmt); //one more time
		test.push_back(a);
	}

	//first outline
	outLine += ",";
	if (zeroChecker == true) {
		for (int i = 0; i < amt; i++) {
			outLine += to_string(i) + ",";
		}
	}
	else {
		for (int i = 0; i < amt; i++) {
			outLine += to_string(i + 1) + ",";
		}
	}
	outLine += "Total";
	outLine += "\n";
	outFile << outLine;
	outLine = "";

	for (int i = 0; i < test.size(); i++) {
		outLine += test[i].area +",";
		for (int j = 0; j < test[i].val.size(); j++) {
			outLine += to_string((double)test[i].val[j]/(double)test[i].total) + ",";
		}
		outLine += to_string(test[i].total);
		outLine += "\n";
		outFile << outLine;
		outLine = "";
	}

	return 0;

}
*/