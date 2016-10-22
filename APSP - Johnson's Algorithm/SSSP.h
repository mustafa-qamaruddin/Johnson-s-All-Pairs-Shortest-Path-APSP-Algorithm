#pragma once
#include "Graph.h"

namespace MQ
{
	class SSSP
	{
	public:
		bool doBellmanFord(Graph g, int s, int*& dp);
		void testBellmanFordTC1();
		void testBellmanFordTC2();
		void testBellmanFordReturn(int* dp, int _sz);
		int doDijkstra(Graph g, int s, int* reweighted_distances);
	};
}