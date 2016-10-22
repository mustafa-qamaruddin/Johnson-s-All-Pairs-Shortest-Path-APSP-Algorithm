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
	//testAddSourceVertex(g);

	// 2 - run bellman-ford
	SSSP sssp;
	int* arr_shortest_paths;
	if (sssp.doBellmanFord(g, 0, arr_shortest_paths))
	{
		//sssp.testBellmanFordReturn(arr_shortest_paths, g.n);
		//sssp.testBellmanFordTC2();

		// 3 - reweighting algorithm
		reweight(g, arr_shortest_paths);
		g.print();

		// 4 - run dijkstra n times
		return loopDijkstra(g, sssp, arr_shortest_paths);
	} 
	else
	{
		return NULL;
	}
	
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
	g.m += g.n;
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
	cout << "m:= " << g.m << endl;
	cout << "Test Add Source Vertex Terminated" << endl;
}

void APSP::reweight(Graph& g, int* arr_shortest_paths)
{
	// undo dummy source vertex effect
	g.m -= g.n;
	int x = 1, y = 0;
	for (int i = 0; i < g.m; i++)
	{
		if ((int)g.adj[x].size() != 0)
		{
			Edge e = g.adj[x][y];
			cout << e.w << " ==> ";
			g.adj[x][y].w = e.w + arr_shortest_paths[e.u] - arr_shortest_paths[e.v];
			cout << e.w << endl;
		}
		else {
			--i;
		}
		++y;
		if (y >= (int)g.adj[x].size())
		{
			++x;
			y = 0;
		}
	}
}

int APSP::loopDijkstra(Graph g, SSSP sssp, int* reweighted_distances)
{
	int ret = INT_MAX;
	for (int i = 1; i <= g.n; i++)
	{
		int d = sssp.doDijkstra(g, i, reweighted_distances);
		if (d < ret)
			ret = d;
	}
	
	return ret;
}