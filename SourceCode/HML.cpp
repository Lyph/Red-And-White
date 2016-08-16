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

class Data{
	int min;
	int max;
	vector<int> column;
};

int main()
{
	vector<vector<int>> grid;
	int amount;
	int count;
	int rowLength = 0;
	string inLine;
	string outLine;
	string firstLine;
	string strInt;
	ofstream out("out.csv"); //where data is going
	ifstream in("in.txt"); //where data is coming

	if (in.is_open())
	{
		getline(in, firstLine);
		for (int i = 0; i < firstLine.length;i++) {
			if (firstLine[i] == '\t') {
				amount++;
				vector<int> temp;
				grid.push_back(temp);
			}
		}
		while (getline(in, inLine))
		{
			for (int i = 0; i < inLine.length;i++) { //for loop to get to first number
				if (inLine[i] == '\t') {
					i++;
					string strInt;
					while (inLine[i] != '\t') {
						strInt += inLine[i];
						i++;
					}
					int num = stoi(strInt);
					grid[rowLength].push_back(num);
					rowLength++;
					if (rowLength == amount) {
						break;
						rowLength = 0;
					}

				}
			}

		}
		in.close();
	}


	return 0;
}
*/