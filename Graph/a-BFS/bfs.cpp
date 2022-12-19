#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define sz(v) ((int)((v).size()))
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)


vector<vector<int>> adj;
// function to add edge to the graph
void addEdge(int x,int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

// Function to perform BFS on the graph
void bfs(int start)
{
	// Visited vector to so that
	// a vertex is not visited more than once
	// Initializing the vector to false as no
	// vertex is visited at the beginning
	vector<bool> visited(adj.size(), false);
	vector<int> q;
	q.push_back(start);

	// Set source as visited
	visited[start] = true;

	int vis;
	while (!q.empty()) {
		vis = q[0];

		// Print the current node
		cout << vis << " ";
		q.erase(q.begin());

		// For every adjacent vertex to the current vertex
		for (int i = 0; i < adj[vis].size(); i++) {
			if (adj[vis][i] == 1 && (!visited[i])) {

				// Push the adjacent node to the queue
				q.push_back(i);

				// Set
				visited[i] = true;
			}
		}
	}
}

// Driver code
int main()
{
// number of vertices
int v = 5;


// adjacency matrix
adj= vector<vector<int>>(v,vector<int>(v,0));

addEdge(0,1);
addEdge(0,2);
addEdge(1,3);

// perform bfs on the graph
bfs(0);
}
