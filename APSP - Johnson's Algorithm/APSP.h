#pragma once
#include "Graph.h"

namespace MQ
{
	class APSP
	{
	public:
		int johnson(Graph g);
		void addSourceVertex(Graph& g);
		void testAddSourceVertex(Graph g);
	};
}
