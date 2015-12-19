#include <iostream>
#include "CountingSet.h"
#include "HuffmanCoding.h"
#include "Compressor.h"
#include "Decompressor.h"
using namespace std;
#define LENGTH 2
int inspectFile(string);
void createMap();

CountingSet cs(LENGTH);
vector<double> pers;
vector<char> chrs;
vector<string> codes;

struct comparison
{
	bool operator() (Pair const &  i, Pair const&  j)
	{
		return (i.code.length()<j.code.length());
	}
} comparer;

vector<Pair> map;

int main()
{
	string fileName, comprName, decomprName;
	cout<<"File name: ";
	cin>>fileName;

    comprName="compressed";

    if (!inspectFile(fileName))
    {
        cout<<"Error inspecting file!";
        cin.get();
        return 0;
    }
    cs.print();
    /*cs.getPercentages(pers);
    cs.getCharacters(chrs);
    HuffmanCoding hCodes(chrs,pers);
    hCodes.getCodes(codes, chrs);
    createMap();
    Compressor comp(map);
    comp.compress(fileName, comprName);
    cout<<"Compression done.";

    decomprName="decompressed";

    Decompressor decomp;
    decomp.decompress(comprName,decomprName);
    cout<<"Decompression done.";


	cin.get();
	return 0;

	if (!inspectFile("testfile.txt"))
	{
		cout<<"Error inspecting file!";
		cin.get();
		return 0;
	}
	cs.getPercentages(pers);
	cs.getCharacters(chrs);
	HuffmanCoding hCodes(chrs,pers);
	hCodes.getCodes(codes, chrs);
	createMap();
	Compressor comp(map);
	comp.compress("testfile.txt", "archive.txt");
	Decompressor decomp;
	decomp.decompress("archive.txt", "testfile2.txt");
	cout<<"Done.";
	cin.get();
	*/return 0;
}

int inspectFile(string name)
{


	ifstream dat;
	dat.open(name, ios::in);
	if (!dat.is_open())
		return 0;
	while (!dat.eof()){
        string fixInputString = "";
        for(int i = 0; i < LENGTH || !dat.is_open(); i++){
            fixInputString.push_back(dat.get());
        }
        cs.addElement(fixInputString);
	}
	dat.close();
	cs.removeLast();
	return 1;
}

void createMap()
{
	for (unsigned i=0; i<chrs.size(); ++i)
	{
		Pair temp;
		temp.ch=chrs[i];
		temp.code=codes[i];
		map.push_back(temp);
	}
	sort(map.begin(), map.end(), comparer);
}
