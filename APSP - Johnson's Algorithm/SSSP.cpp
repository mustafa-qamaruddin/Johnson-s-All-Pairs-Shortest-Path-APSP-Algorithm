#include "stdafx.h"
#include "SSSP.h"
#include "Graph.h"
#include "Edge.h"
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>

using namespace std;
using namespace MQ;

bool SSSP::doBellmanFord(Graph g, int s, int*& dp)
{
	cout << "Bellman-Ford Started" << endl;
	dp = new int[g.n + 1];

	dp[s] = 0;
	for (int i = 0; i <= g.n; i++)
		if (i != s)
			dp[i] = INT_MAX;

	for (int i = 1; i <= g.n; i++)
	{
		int x = 0, y = 0;
		for (int j = 0; j < g.m; j++)
		{
			if ((int)g.adj[x].size() != 0) {
				Edge e = g.adj[x][y];
				if (dp[e.u] != INT_MAX)
					dp[e.v] = min(dp[e.v], dp[e.u] + e.w);
			}

			++y;
			if (y >= (int)g.adj[x].size())
			{
				++x;
				y = 0;
			}
		}
	}

	// detect negative cost cycle
	int x = 0, y = 0;
	for (int j = 0; j < g.m; j++)
	{
		if ((int)g.adj[x].size() != 0) {
			Edge e = g.adj[x][y];
			if (dp[e.u] + e.w < dp[e.v])
			{
				cerr << "Negative Cost Cycle Detected" << endl;
				return false;
			}
		}
		
		++y;
		if (y == (int)g.adj[x].size())
		{
			++x;
			y = 0;
		}
	}

	cout << "Bellman-Ford Terminated" << endl;

	return true;
}

void SSSP::testBellmanFordTC1()
{
	Graph g;
	g.n = 3;
	g.m = 6;
	for(int i = 0; i <= g.n; i++)
		g.adj.push_back(vector<Edge>());
	
	Edge e;
	e.u = 0; e.v = 1; e.w = 0;
	g.adj[0].push_back(e);
	e.u = 0; e.v = 2; e.w = 0;
	g.adj[0].push_back(e);
	e.u = 0; e.v = 3; e.w = 0;
	g.adj[0].push_back(e);

	e.u = 1; e.v = 2; e.w = -1;
	g.adj[1].push_back(e);
	e.u = 1; e.v = 3; e.w = 2;
	g.adj[1].push_back(e);

	e.u = 2; e.v = 3; e.w = 4;
	g.adj[2].push_back(e);

	cout << "Bellman-Ford - TEST CASE #1:" << endl;
	int* arr_shortest_paths;
	doBellmanFord(g, 0, arr_shortest_paths);
}

void SSSP::testBellmanFordTC2()
{
	Graph g;
	g.n = 3;
	g.m = 6;
	for (int i = 0; i <= g.n; i++)
		g.adj.push_back(vector<Edge>());

	Edge e;
	e.u = 0; e.v = 1; e.w = 0;
	g.adj[0].push_back(e);
	e.u = 0; e.v = 2; e.w = 0;
	g.adj[0].push_back(e);
	e.u = 0; e.v = 3; e.w = 0;
	g.adj[0].push_back(e);

	e.u = 1; e.v = 2; e.w = -1;
	g.adj[1].push_back(e);
	e.u = 3; e.v = 1; e.w = -1;
	g.adj[1].push_back(e);

	e.u = 2; e.v = 3; e.w = -2;
	g.adj[2].push_back(e);

	cout << "Bellman-Ford - TEST CASE #2:" << endl;
	int* arr_shortest_paths;
	doBellmanFord(g, 0, arr_shortest_paths);
}

void SSSP::testBellmanFordReturn(int* dp, int _sz)
{
	cout << "Bellman-Ford Results:" << endl;
	for (int i = 0; i <= _sz; i++)
	{
		cout << "Shortest Path (0," << i << ") = " << dp[i] << endl;
	}
}

int SSSP::doDijkstra(Graph g, int s, int* reweighted_distances)
{
	cout << "Dijkstra Subroutine Started:" << endl;
	int* arr_temp_weights = new int[g.n + 1];
	fill(arr_temp_weights, arr_temp_weights + g.n + 1, INT_MAX);
	struct cmp
	{
		bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
		{
			return lhs.second > rhs.second;
		}
	};
	priority_queue <pair<int, int> , vector<pair<int, int> >, cmp > pq;
	pq.push(pair<int, int>(s, 0));
	arr_temp_weights[s] = 0;

	while (!pq.empty())
	{
		pair<int, int> pr = pq.top();
		pq.pop();
		int vertex = pr.first;
		int weight = pr.second;
		for (int i = 0; i < (int)g.adj[vertex].size(); i++)
		{
			int idx = g.adj[vertex][i].v;
			if (weight + g.adj[vertex][i].w < arr_temp_weights[i])
			{
				arr_temp_weights[i] = weight + g.adj[vertex][i].w;
				pq.push(pair<int, int>(i, arr_temp_weights[i]));
			}
		}
	}

	int ret = INT_MAX;
	for (int i = 1; i < g.n + 1; i++) {
		if (i == s)
			continue;
		// reweighting step
		if(arr_temp_weights[i] != INT_MAX)
			arr_temp_weights[i] = arr_temp_weights[i] - reweighted_distances[s] + reweighted_distances[i];
		if (arr_temp_weights[i] < ret)
		{
			ret = arr_temp_weights[i];
		}
	}
		

	cout << "Dijkstra Subroutine Terminated" << endl;
	return ret;
}