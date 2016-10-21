#pragma once
#include <string>
#include "Edge.h"
#include <vector>

using namespace std;

namespace MQ
{
	class Graph
	{
	public:
		bool readFromFile(string file_name);
		void print();
		// n := |V|
		// m := |E|
		int n, m;
		vector< vector<Edge> > adj;
	};
};