// APSP - Johnson's Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "APSP.h"

using namespace std;

int main()
{
	cout << "Operation APSP Started" << endl;
	MQ::Graph g;
	g.readFromFile("TCs/g1.txt");
	g.print();
	MQ::APSP apsp;
	apsp.johnson(g);
	cout << "Operation APSP Terminated" << endl;
    return 0;
}

