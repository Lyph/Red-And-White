//
//#include <iostream> 
//#include <string> 
//#include <fstream> 
//#include <iomanip> 
//#include <iostream>
//#include <stdlib.h> 
//#include <bitset> 
//#include <vector> 
//#include <math.h> 
//#include <algorithm> 
////#include "stdafx.h" //for Visual Studios 
//
//using namespace std;
//
//int converter() {
//	ofstream outFile("in.txt"); //where data is going
//	ifstream file("input.csv");
//	string inLine;
//	string outLine;
//	int maxLength = 0;
//
//	if (file.is_open())
//	{
//		getline(file, inLine);
//		for (int i = 0; i < inLine.length(); i++) {
//			if (inLine[i] == ',') {
//				maxLength++;
//			}
//		}
//		maxLength++;
//
//		do {
//			for (int i = 0; i < inLine.length(); i++) {
//				if (inLine[i] == ',') {
//					outLine += "\n";
//				}
//				else {
//					outLine += inLine[i];
//				}
//			}
//			outLine += "\n";
//			outFile << outLine;
//			outLine = "";
//		}
//
//		while (getline(file, inLine));
//
//		file.close();
//	}
//
//	return maxLength;
//}
//
//struct range {
//	int lowerMin; int lowerMax;
//	int middleMin; int middleMax;
//	int highMin; int highMax;
//
//};
//
//int main()
//{
//	vector<vector<int>> grid;
//	vector<range> Range;
//	vector<vector<int>> original;
//	vector<vector<int>> changed;
//	vector<string> column;
//	vector<string> firstRow;
//	string inLine;
//	string outLine;
//	int maxLength = converter();
//	//cin >> maxLength;
//	for (int i = 0; i < maxLength - 1;i++) {
//		vector<int> temp;
//		grid.push_back(temp);
//	}
//	for (int i = 0; i < maxLength - 1;i++) {
//		range temp;
//		Range.push_back(temp);
//	}
//	int count = 0;
//	ofstream outFile("output.csv"); //where data is going
//	ifstream file("in.txt"); //where data is coming
//	if (file.is_open())
//	{
//		for (int i = 0; i < maxLength;i++) {
//			getline(file, inLine);
//			firstRow.push_back(inLine);
//		}
//		while (getline(file, inLine))
//		{
//			count++;
//
//			if (count == 1) { column.push_back(inLine); }
//
//			else {
//				int num = stoi(inLine);
//				grid[count - 2].push_back(num);
//				if (count == maxLength) {
//					count = 0;
//				}
//			}
//
//		}
//		file.close();
//	}
//	original = grid;
//	changed = grid;
//
//
//	for (int i = 0; i < maxLength - 1;i++) {
//		sort(grid[i].begin(), grid[i].end());
//	}
//	for (int i = 0; i < maxLength - 1;i++) {
//		int length = grid[i].size();
//		Range[i].lowerMax = grid[i].at(length * 1 / 3);
//		Range[i].middleMax = grid[i].at(length * 2 / 3);
//		Range[i].highMax = grid[i].at(length - 1);
//
//		Range[i].lowerMin = grid[i].at(0);
//		Range[i].middleMin = Range[i].lowerMax;
//		int increment = 0;
//		while (Range[i].middleMin == Range[i].lowerMax) {
//			increment++;
//			Range[i].middleMin = grid[i].at(length * 1 / 3 + increment);
//		}
//		Range[i].highMin = Range[i].middleMax;
//		increment = 0;
//		while (Range[i].highMin == Range[i].middleMax) {
//			increment++;
//			Range[i].highMin = grid[i].at(length * 2 / 3 + increment);
//		}
//	}
//
//
//	for (int i = 0; i < changed.size();i++) {
//		//cout << Range[i].lowerMin + " " + Range[i].lowerMax + " " + Range[i].middleMin + " " + Range[i].middleMax + " " +Range[i].highMin + " " + Range[i].highMax;
//		for (int j = 0; j < changed[i].size(); j++) {
//			if (changed[i].at(j) >= Range[i].highMin) {
//				changed[i].at(j) = 5;
//			}
//			else if (changed[i].at(j) >= Range[i].middleMin) {
//				changed[i].at(j) = 3;
//			}
//			else {
//				changed[i].at(j) = 1;
//			}
//
//		}
//	}
//		outLine += firstRow.at(0)+",";
//		for (int i = 1; i < maxLength; i++) {
//			outLine += firstRow.at(i) +",,";
//		}
//		outLine += "\n";
//		outFile << outLine;
//		outLine = "";
//
//		for (int j = 0; j < changed[0].size(); j++) {
//			outLine += column.at(j) + ",";
//			for (int i = 0; i < changed.size();i++) {
//			
//			outLine += to_string(original[i].at(j)) + ",";
//			outLine += to_string(changed[i].at(j)) + ",";
//
//		}
//			outLine += "\n";
//			outFile << outLine;
//			outLine = "";
//	}
//		outFile << "\n \n ";
//
//		outLine += "Scoring,";
//		for (int i = 0; i < (maxLength - 1) / 2; i++) {
//			outLine += "Min " + to_string(i+1) + ",";
//			outLine += "Max " + to_string(i+1) + ",";
//		}
//		outLine += "\n";
//		outFile << outLine;
//		outLine = "";
//		
//		for (int i = 0; i < maxLength-1; i++) {
//			outLine += firstRow.at(i+1) + ",";
//			outLine += to_string(Range[i].lowerMin) + ",";
//			outLine += to_string(Range[i].lowerMax) + ",";
//			outLine += to_string(Range[i].middleMin) + ",";
//			outLine += to_string(Range[i].middleMax) + ",";
//			outLine += to_string(Range[i].highMin) + ",";
//			outLine += to_string(Range[i].highMax) + ",";
//			outLine += "\n";
//			outFile << outLine;
//			outLine = "";
//		}
//	return 0;
//}
//
