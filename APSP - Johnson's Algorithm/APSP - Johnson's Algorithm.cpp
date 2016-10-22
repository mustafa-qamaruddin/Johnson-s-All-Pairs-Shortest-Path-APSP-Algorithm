// APSP - Johnson's Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "APSP.h"
#include <sstream>

using namespace std;

int main()
{
	cout << "Operation APSP Started" << endl;
	for (int i = 3; i <= 3; i++)
	{
		cout << "TEST CASE #" << i << endl;
		MQ::Graph g;
		ostringstream ss;
		ss << "TCs/g" << i << ".txt";
		g.readFromFile(ss.str());
		MQ::APSP apsp;
		cout << "Minimum Pair: " << apsp.johnson(g);
		cout << endl << endl;
	}
	cout << "Operation APSP Terminated" << endl << endl;
    return 0;
}