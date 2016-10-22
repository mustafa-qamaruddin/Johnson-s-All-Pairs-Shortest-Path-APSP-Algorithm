#pragma once
#include "Graph.h"
#include "SSSP.h"

namespace MQ
{
	class APSP
	{
	public:
		int johnson(Graph g);
		void addSourceVertex(Graph& g);
		void testAddSourceVertex(Graph g);
		void reweight(Graph& g, int* arr_shortest_paths);
		int loopDijkstra(Graph g, SSSP sssp, int* reweighted_distances);
	};
}
