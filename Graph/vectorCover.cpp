/*
    In this problem we are given an undirected graph and we need to find the minimum subset of nodes such that each node is visited and the complete graph is covered.

    Given a graph G(V,E) and integer k we need to find a subset such that it's size is less than or equal to k.

    A common approach is backtracking with branching (recursive search):
    * Pick any edge (u,v)
    * Either include u in the cover OR include v
    * Reduce k and recurse
    * If no edges remain → success
    
    It's complexity is O(2^k⋅(V+E))
*/

#include <bits/stdc++.h>
using namespace std;

bool vertexCover(vector<pair<int,int>> edges, int k) {
    if (edges.empty()) return true;
    if (k == 0) return false;

    // Pick first edge
    auto edge = edges[0];
    int u = edge.first;
    int v = edge.second;

    // Case 1: include u
    vector<pair<int,int>> newEdges1;
    for (auto &e : edges) {
        if (e.first != u && e.second != u)
            newEdges1.push_back(e);
    }
    if (vertexCover(newEdges1, k - 1)) return true;

    // Case 2: include v
    vector<pair<int,int>> newEdges2;
    for (auto &e : edges) {
        if (e.first != v && e.second != v)
            newEdges2.push_back(e);
    }
    if (vertexCover(newEdges2, k - 1)) return true;

    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (vertexCover(edges, k))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}