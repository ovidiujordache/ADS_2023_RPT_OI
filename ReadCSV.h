#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ReadCSV {
public :
	void readCSV()
	{
		cout << "\nReading csv file" << endl;

		ifstream fileInStr;
		string row;
		fileInStr.open("CSVFiles/janes_leads_20.csv", ios::in);

		while (!fileInStr.eof()) {
			fileInStr >> row;
			cout << row << endl;
		}
	}

};