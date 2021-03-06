#include "PrimMST.hpp"
#include <fstream>

using namespace std;

vector<vector<int>> readFromFile(ifstream & input)
{
	vector<vector<int>> graph;

	int current = 0;
	int i = 0;
	
	while (!input.eof())
	{
		vector<int> matrixRow;
		graph.push_back(matrixRow);

		while (!input.eof() && input.peek() != '\n')
		{
			input >> current;
			graph[i].push_back(current);
		}
		input.get();
		++i;
	}

	return graph;
}

int minKey(const vector<int> & key, const vector<bool> & set)
{
	int min = INF;
	int res = 0;

	for (int i = 0; i < set.size(); ++i)
	{
		if (!set[i] && key[i] < min)
		{
			min = key[i];
			res = i;
		}
	}

	return res;
}

void primMST(vector<int> & parents, const vector<vector<int>> & graph)
{
	vector<int> key(graph.size());
	// set to keep vetricles which haven't been added to spanning tree
	vector<bool> set(graph.size());

	for (int i = 0; i < graph.size(); i++)
	{
		key[i] = INF;
		set[i] = false;
	}

	key[0] = 0;
	parents[0] = -1;

	for (int counter = 0; counter < graph.size() - 1; ++counter)
	{
		int minimumKey = minKey(key, set);
		// add to set
		set[minimumKey] = true;

		for (int i = 0; i < graph.size(); ++i)
		{
			if (graph[minimumKey][i] && set[i] == false && graph[minimumKey][i] < key[i])
			{
				parents[i] = minimumKey;
				key[i] = graph[minimumKey][i];
			}
		}
	}
}