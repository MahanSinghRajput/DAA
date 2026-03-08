#include <iostream>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rank[pu] < rank[pv])
            parent[pu] = pv;
        else if(rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int kruskal(int V, vector<vector<int>> &edges) {

    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });

    DisjointSet ds(V);
    int mstWeight = 0;

    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(ds.findParent(u) != ds.findParent(v)) {
            mstWeight += wt;
            ds.unionByRank(u, v);
        }
    }

    return mstWeight;
}

int main() {

    int V = 4;

    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    cout << "MST Weight: " << kruskal(V, edges);
}