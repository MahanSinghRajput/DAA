/*
    Similar problem but now we need to print the subset.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bestCover;

// Function to solve recursively
void findVertexCover(vector<pair<int,int>> edges, vector<int> currentCover) {
    
    // If no edges left → valid vertex cover
    if (edges.empty()) {
        if (bestCover.empty() || currentCover.size() < bestCover.size()) {
            bestCover = currentCover;
        }
        return;
    }

    // Pruning: stop if already worse than best solution
    if (!bestCover.empty() && currentCover.size() >= bestCover.size()) {
        return;
    }

    // Pick first edge
    int u = edges[0].first;
    int v = edges[0].second;

    // -------- Case 1: include u --------
    vector<pair<int,int>> edgesWithoutU;
    for (auto &e : edges) {
        if (e.first != u && e.second != u)
            edgesWithoutU.push_back(e);
    }

    currentCover.push_back(u);
    findVertexCover(edgesWithoutU, currentCover);
    currentCover.pop_back();

    // -------- Case 2: include v --------
    vector<pair<int,int>> edgesWithoutV;
    for (auto &e : edges) {
        if (e.first != v && e.second != v)
            edgesWithoutV.push_back(e);
    }

    currentCover.push_back(v);
    findVertexCover(edgesWithoutV, currentCover);
    currentCover.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    findVertexCover(edges, {});

    // Print result
    for (int v : bestCover) {
        cout << v << " ";
    }

    return 0;
}