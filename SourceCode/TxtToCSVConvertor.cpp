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

int main()
{
	string inLine;
	string outLine;
	int count = 0;
	ofstream outFile("out.csv"); //where data is going
	ifstream file("in.txt"); //where data is coming
	if (file.is_open())
	{
		while (getline(file, inLine))
		{
			count++;
			//ignore numbering
			//if (count == 1) { continue; }

	
			if (count == 14) {
				//We add double quotes so the CSV file can ignore address commas
				outLine = outLine + "\"" + inLine + "\",";
				outFile << outLine +"\n";
				count = 0;
				outLine = "";
			}

			else {
				outLine = outLine + "\"" + inLine + "\",";
			}

		}
		file.close();
	}


	return 0;
}*/