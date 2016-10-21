#include "stdafx.h"
#include "APSP.h"
#include "Edge.h"
#include "SSSP.h"
#include <iostream>

using namespace std;
using namespace MQ;

int APSP::johnson(Graph g)
{
	// 1 - add source vertex
	addSourceVertex(g);
	testAddSourceVertex(g);

	// 2 - run bellman-ford
	SSSP sssp;
	sssp.doBellmanFord(g, 0);

	// 3 - reweighting algorithm

	// 4 - run dijkstra n times

	// 5 - undo reweighting algorithm

	// 6 - return minimum APSP
	return -1;
}

void APSP::addSourceVertex(Graph& g)
{
	for (int i = 1; i <= g.n; i++)
	{
		Edge e;
		e.u = 0;
		e.v = i;
		e.w = 0;
		g.adj[0].push_back(e);
	}
}

void APSP::testAddSourceVertex(Graph g)
{
	cout << "Test Add Source Vertex Started" << endl;
	int len = (int)g.adj[0].size();
	cout << "Adjacency List of Source Vector Length: " << len << endl;
	for (int i = 0; i < len; i++)
	{
		cout << g.adj[0][i].v << " , " << g.adj[0][i].w << endl;
	}
	cout << "Test Add Source Vertex Terminated" << endl;
}