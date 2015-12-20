#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class CountingSet
{
private:
    int stringsLenght;
	struct Element
	{
		string s; // string of each piece of code
		int count;  // number of occurrences
		void print(){ cout << s << " : " << count << endl; }
	};
	vector<Element> ems;
public:
	CountingSet(int s);
	~CountingSet(void);
	void addElement(string);
	void removeLast();
	void getPercentages(vector<double>&);
	void getStrings(vector<string>&);
	void print();
};

