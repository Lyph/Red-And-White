
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

int converter() {
	vector<int> score;
	ofstream outFile("in.txt"); //where data is going
	ifstream file("input.csv");
	
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

vector<int> initScore() {
	vector<int> temp;
	double split;
	double maxScore;
	cout << "Max Score: ";
	cin >> maxScore;
	cout << "Split: ";
	cin >> split;
	int score = maxScore;
	int interval = ceil(maxScore / split);
	do {
		temp.push_back(score);
		score = score - interval;
	} while (score > 0);

	//reverse(temp.begin(), temp.end());
	return temp;

}



int main()
{
	vector<vector<double>> grid;
	vector<int> score = initScore();
	vector<vector<double>> Range;
	vector<vector<double>> original;
	vector<vector<double>> changed;
	vector<string> column;
	vector<string> firstRow;
	string inLine;
	string outLine;
	int maxLength = converter();
	//cin >> maxLength;
	for (int i = 0; i < maxLength - 1;i++) {
		vector<double> temp;
		grid.push_back(temp);
	}
	for (int i = 0; i < maxLength - 1;i++) {
		vector<double> temp;
		Range.push_back(temp);
	}

	int count = 0;
	ofstream outFile("output.csv"); //where data is going
	ifstream file("in.txt"); //where data is coming
	if (file.is_open())
	{
		for (int i = 0; i < maxLength;i++) {
			getline(file, inLine);
			firstRow.push_back(inLine);
		}
		while (getline(file, inLine))
		{
			count++;

			if (count == 1) { column.push_back(inLine); }

			else {
				double num = stod(inLine);
				grid[count - 2].push_back(num);
				if (count == maxLength) {
					count = 0;
				}
			}

		}
		file.close();
	}
	original = grid;
	changed = grid;


	for (int i = 0; i < maxLength - 1;i++) {
		sort(grid[i].begin(), grid[i].end());
	}

	
	for (int i = 0; i < maxLength - 1;i++) {
		Range[i].push_back(grid[i].at(0)); //first min
		for (int j = 0; j < score.size(); j++) {
			int increment = grid[i].size() * (j + 1) / score.size();
			if (increment == grid[i].size()) {
				Range[i].push_back(grid[i].at(increment-1));
				break; 
			}//end of "row"
			Range[i].push_back(grid[i].at(increment)); //max
			if (Range[i].at(Range[i].size() - 1) < Range[i].at(Range[i].size() - 2)) { Range[i].at(Range[i].size() - 1) = Range[i].at(Range[i].size() - 2); }
			int offset = increment+1;
			while (grid[i].at(offset) <= grid[i].at(increment)) {
				offset++;
				if (offset >= grid[i].size() - 1) {
					offset = grid[i].size() - 2;
					break;
				}
			}
			Range[i].push_back(grid[i].at(offset)); //min
		}
	}


	for (int i = 0; i < changed.size();i++) {
		for (int j = 0; j < changed[i].size(); j++) {
			for (int k = 0; k < Range[i].size(); k++){
				//	curent value		current min
				if (changed[i].at(j) >= Range[i].at(Range[i].size() - 2 * (k + 1))) {
					changed[i].at(j) = score[k];
					break; //no need to continue for current value
				}
			}
		}
	}
	string firstLine;
	firstLine += firstRow.at(0) + ",";
	for (int i = 1; i < maxLength; i++) {
		firstLine += firstRow.at(i) + ",,";
	}
	firstLine += "\n";
	outFile << firstLine;

	for (int j = 0; j < changed[0].size(); j++) {
		outLine += column.at(j) + ",";
		for (int i = 0; i < changed.size();i++) {

			outLine += to_string(original[i].at(j)) + ",";
			outLine += to_string(changed[i].at(j)) + ",";

		}
		outLine += "\n";
		outFile << outLine;
		outLine = "";
	}
	outFile << "\n \n " + firstLine;

	outLine += "Scoring,";
	for (int i = 0; i < (maxLength - 1); i++) {
		outLine += "Min " + to_string(i + 1) + ",";
		outLine += "Max " + to_string(i + 1) + ",";
	}
	outLine += "\n";
	outFile << outLine;
	outLine = "";
	
	reverse(score.begin(), score.end());


	for (int i = 0; i < score.size(); i++) { //# of columns
		outLine += to_string(score[i]) + ",";
		int interval = i * 2;
		for (int j = 0; j < (maxLength - 1); j++) {
			outLine += to_string(Range[j].at(interval)) + ",";
			outLine += to_string(Range[j].at(interval+1)) + ",";
		}
		outLine += "\n";
		outFile << outLine;
		outLine = "";
	}
	remove("in.txt");

	return 0;
}

