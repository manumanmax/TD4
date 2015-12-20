#include <iostream>
#include "CountingSet.h"
#include "HuffmanCoding.h"
#include "Compressor.h"
#include "Decompressor.h"
using namespace std;
int inspectFile(string);
void createMap();

CountingSet cs(LENGTH);
vector<double> pers;
vector<string> strings;
vector<string> codes;

struct comparison
{
	bool operator() (Pair const &  i, Pair const&  j)
	{
		return (i.code.length()<j.code.length());
	}
} comparer;

vector<Pair> map;
void printMap();
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

    cs.getPercentages(pers);
    cs.getStrings(strings);
    //cs.print();
    HuffmanCoding hCodes(strings,pers);
    hCodes.getCodes(codes, strings);
    createMap();
    printMap();
    Compressor comp(map);
    comp.compress(fileName, comprName);
    cout<<"Compression done.";

    /*decomprName="decompressed";

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
	for (unsigned i=0; i<strings.size(); ++i)
	{
		Pair temp;
		temp.str=strings[i];
		temp.code=codes[i];
		map.push_back(temp);
	}
	sort(map.begin(), map.end(), comparer);
}

void printMap(){

    for(Pair p : map){
        cout << p.str << " -> " << p.code << endl;
    }
}
