#pragma once
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class HuffmanCoding
{
private:
	struct Element
	{
		char c;
		string code;
	};

	struct Node
	{
		char c;
		string code;
		double probab;
		Node *left, *right;
	};

	struct comparison
	{
		bool operator() (Node* const& i, Node* const& j)
		{
			return (i->probab<j->probab);
		}
	} comparer;

	vector<Element> codes;
	vector<Node*> nodes;
	Node *root;
	void generateCodes();
public:
	HuffmanCoding(vector<char>&, vector<double>&);
	~HuffmanCoding(void);
	void getCodes(vector<string>&, const vector<char>&);
};

