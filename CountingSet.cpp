#include "CountingSet.h"

CountingSet::CountingSet(int stringsLenght): stringsLenght(stringsLenght){}

CountingSet::~CountingSet(void) { }

void CountingSet::addElement(string e)
{
	for (unsigned i=0; i<ems.size(); ++i)
		if (ems[i].s==e)
		{
			++ems[i].count;
			return;
		}
	Element temp;
	temp.s=e;
	temp.count=1;
	ems.push_back(temp);
}

void CountingSet::getPercentages(vector<double>& percs)
{
	int count=0;
	for (unsigned i=0; i<ems.size(); ++i)
	{
		count+=ems[i].count;
		percs.push_back(ems[i].count*100);
	}
	for (unsigned i=0; i<ems.size(); ++i)
		percs[i]/=count;
}


void CountingSet::getStrings(vector<string>& strings)
{
	for (unsigned i=0; i<ems.size(); ++i)
		strings.push_back(ems[i].s);
}

void CountingSet::removeLast()
{
	ems.pop_back();
}

void CountingSet::print(){

    for(auto e: ems){
        e.print();
    }
}
