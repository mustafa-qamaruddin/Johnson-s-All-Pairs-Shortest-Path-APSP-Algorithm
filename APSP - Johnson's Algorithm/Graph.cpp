#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace MQ;

bool Graph::readFromFile(string file_name)
{
	ifstream fs;
	fs.open(file_name.c_str(), ifstream::in);

	if (!fs.is_open())
		return false;

	fs >> n >> m;

	// initialize adjancy list array
	for (int i = 0; i <= n; i++)
	{
		adj.push_back(vector<Edge>());
	}

	// n+1 vertices for dummy start vertex s at pos 0
	for (int i = 0; i < m; i++)
	{
		Edge e;
		fs >> e.u >> e.v >> e.w;
		adj[e.u].push_back(e);
	}
}

void Graph::print()
{
	for (int i = 0; i <= n; i++)
	{
		cout << "Adjacency List of Vertex (" << i << "): " << endl;
		for (int j = 0; j < (int)adj[i].size(); j++)
		{
			cout << adj[i][j].v << " , " << adj[i][j].w << endl;
		}
	}
}