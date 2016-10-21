#include "stdafx.h"
#include "SSSP.h"
#include "Graph.h"
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
using namespace MQ;

void SSSP::doBellmanFord(Graph g, int s)
{
	cout << "Bellman-Ford Started" << endl;
	int** dp = new int*[g.n + 1];
	for (int i = 0; i <= g.n; i++)
		dp[i] = new int[g.n + 1];

	dp[0][s] = 0;
	for (int i = 0; i <= g.n; i++)
		if (i != s)
			dp[0][i] = INT_MAX;

	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			// brute force in-vertices(j)
			dp[i, j] = min(dp[i - 1, j], dp[i - 1, j]);
		}
	}

	cout << "Shortest Path d(0,1000): " << dp[g.n - 1, 1000] << endl;
	// detect negative cycle run one extra iteration
	cout << "Bellman-Ford Terminated" << endl;
}