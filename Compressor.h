#pragma once
#include <vector>
#include <fstream>
#include <cmath>
#include <iostream>
#include <string>
#define LENGTH 2

using namespace std;

struct Pair
{
	string str;
	string code;
};

class Compressor
{
private:
	bool done;
	short endBlanks;
	vector<Pair> map;
	vector<string> head;
	string bodyBuffer;
	string fromFile;
	string toFile;
	void createHead();
	void createBody();
	void clearBuffer();
	string loadBuffer(ifstream&);
public:
	Compressor(vector<Pair>&);
	~Compressor(void);
	void compress(string, string);
};
