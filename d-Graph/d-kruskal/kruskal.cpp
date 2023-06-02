#include <set>
#include <map>
#include <array>
#include <list>
#include <iomanip>
#include <cmath>
#include <climits>
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
#define sz(v) ((lol)((v).size()))
#define all(v) ((v).begin()), ((v).end())
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopx(n) for (int x = 0; x < n; x++)
#define loopR(x, n) for (int i = x; i <= (int)(n); ++i)
#define loopSz(v) for (int i = 0; i < sz(v); ++i)
#define loopItr(structure) for (auto itr = structure.begin(); itr != structure.end(); itr++)
#define BREAK cout << "--------------------------------------------------------------------" << endl
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
lol gcd(lol a, lol b)
{
    return b == 0 ? a : gcd(b, a % b);
}
lol lcm(lol a, lol b) { return a / gcd(a, b) * b; }
const lol OO = 1e8;

struct DisjointSet
{
    vector<int> rank;
    vector<int> parent;

    int forests;

    DisjointSet(int size)
    {
        rank = vector<int>(size);
        parent = vector<int>(size);

        forests = size;

        loop(i, size)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find_top_parent(int node)
    {
        if (node == parent[node]) // the root of the tree
            return node;

        return parent[node] = find_top_parent(parent[node]); // to apply path compression
    }

    void union_nodes(int x, int y)
    {
        if (rank[x] > rank[y])
            swap(x, y);

        parent[x] = y; // union the small with the big

        /*
            after union if rank x =4 , rank y = 4, so rank y = 5
            if rank  x was smaller than rank y we don't need to change any thing because we always save the bigger rank
            remember the rank x can't be bigger than rank y because we swap it
        */
        if (rank[x] == rank[y])
            rank[y]++;
    }

    bool same_parent(int x, int y)
    {
        return find_top_parent(x) == find_top_parent(y);
    }

    bool union_forests(int x, int y)
    {
        int parentX = find_top_parent(x);
        int parentY = find_top_parent(y);

        if (parentX != parentY)
        {
            union_nodes(parentX, parentY);
            forests--;
        }

        return parentX != parentY; // return the result of success or failure of union
    }

    vector<vector<int>> connected_components()
    {
        vector<vector<int>> list(sz(parent));

        loopSz(parent)
        {
            list[find_top_parent(i)].push_back(i);
        }

        return list;
    }
};

struct Edge
{
    int from, to, w;

    Edge(int from, int to, int w) : from(from), to(to), w(w) {}

    bool operator<(const Edge &e) const
    {
        return w > e.w; // STL priority_queue need it >
    }
};

pair<int, vector<Edge>> kruskal(vector<Edge> edgeList, int size) // o(E logV)
{
    DisjointSet disjointSet(size);

    vector<Edge> edges;
    int mstCost = 0;

    priority_queue<Edge> que;

    // add all to queue to become the first one is smallest
    loopSz(edgeList) que.push(edgeList[i]);

    while (!que.empty())
    {
        Edge edge = que.top();
        que.pop();

        if (disjointSet.union_forests(edge.to, edge.from))
        {
            mstCost += edge.w;
            edges.push_back(edge);
        }
    }

    if (sz(edges) != size - 1)
        return make_pair(-OO, vector<Edge>());

    return make_pair(mstCost, edges);
}

int main()
{
    mino;
}