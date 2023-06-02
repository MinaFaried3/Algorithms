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
struct edge
{
    int from, to, w;

    edge(int from, int to, int w) : from(from), to(to), w(w) {}

    bool operator<(const edge &e) const
    {
        return w > e.w; // STL priority_queue need it >
    }
};

// Find MST value & edges. adjMax is initialized by OO
pair<int, vector<edge>> prim_adjMax(vector<vector<int>> adjMax) // O(n^2)
{
    int currNode = 0;
    int size = sz(adjMax);
    int mstCost = 0;

    vector<bool> visited(size, false);
    vector<int> previous(size);
    vector<int> distance(size, OO); // 1) dist[i]: Minimum value to connect i to current built tree
    vector<edge> edges;             // Save MST edges

    loop(i, size - 1)
    {
        visited[currNode] = true;
        int minDistance = OO;
        int minIdx = -1;

        loop(x, size)
        {
            if (!visited[x])
            {
                // 2) Update if i can reach tree with a new Minimum value
                if (adjMax[currNode][x] < distance[x])
                {
                    distance[x] = adjMax[currNode][x];
                    previous[x] = currNode;
                }

                // 3) Select minimum EDGE value
                if (distance[x] < minDistance)
                {
                    minDistance = distance[x];
                    minIdx = x;
                }
            }
        }

        // 4) check if graph is disconnected
        if (minIdx == -1)
            break;

        // 5) update edges and cost of mst
        edges.push_back(edge(previous[minIdx], minIdx, adjMax[previous[minIdx]][minIdx]));

        currNode = minIdx;
        mstCost += distance[currNode];
    }

    if (sz(edges) != size - 1)
        return make_pair(OO, vector<edge>());

    return make_pair(mstCost, edges);
}

pair<int, vector<edge>> PRIM_MST2(vector<vector<edge>> adjList) // O(E logV)
{                                                               // edge x-->y & y-->x	must be in the adjList
    int size = sz(adjList), mstCost = 0;
    vector<bool> vis(size, false);
    vector<edge> edges; // Save MST edges

    priority_queue<edge> que; // 1) priority_queue to sort edges
    que.push(edge(-1, 0, 0));

    while (!que.empty())
    {
        edge edg = que.top();
        que.pop();

        if (vis[edg.to])
            continue;

        vis[edg.to] = true;
        mstCost += edg.w;
        if (edg.to)
            edges.push_back(edg); // 2) remove min element & update cost/list

        loopSz(adjList[edg.to])
        {   // 3) Iterate on adjacent edges & add new edges, using e.to as src
            edge newEdg = adjList[edg.to][i];
            if (!vis[newEdg.to]) // 4) If added will cause cycle
                que.push(newEdg);
        }
    }

    if (sz(edges) != size - 1)
        return make_pair(-OO, vector<edge>());
    return make_pair(mstCost, edges);
}

int main()
{
}