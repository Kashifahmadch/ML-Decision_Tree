//============================================================================
// Name        : Assignment1(C++).cpp
// Author      : Kashif Ahmed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//#include <cstdlib> strtol(s.c_str(),0,10);
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

vector<string> attributes;
vector<vector<int> > attributesValues;

void ParseCSV() {

	char delimeter = ',';
	string line;

	ifstream myfile ("training_set.csv");

	if (myfile.is_open())
	{
		getline(myfile, line);

		stringstream ss(line);
		string token;

		//Get attributes
		while (getline(ss, token, delimeter)) {

			attributes.push_back(token);

			//create the vector containing values for this attribute
			vector<int> attribute;
			attributesValues.push_back(attribute);
		}

		//Get values
		while ( getline (myfile,line) )
		{
		  stringstream ss(line);
		  string token;

		  int attributeIndex = 0;
		  while (getline(ss, token, delimeter)) {

			attributesValues.at(attributeIndex).push_back(stoi(token));
			attributeIndex++;
		  }
		}
	}
	else
	{
		cout << "Unable to open file";
	}

	myfile.close();
}

void Print() {

	for(int i=0; i< attributes.size(); i++) {

		string attribute = attributes.at(i);
		cout<<attribute << " ";

		vector<int> row = attributesValues.at(i);

		for(int j=0; j< row.size(); j++) {

			int value = row.at(j);
			cout<<value << " ";
		}

		cout << " end " <<endl;
	}
}

int main()
{
	ParseCSV();
	Print();
	return 0;
}
