#include<iostream>
using namespace std;
int prims(int V, vector<vector<pair<int,int>>>& adj) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> visited(V, 0);

    pq.push({0, 0}); // {weight, node}
    int sum = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int wt = it.first;
        int node = it.second;

        if(visited[node]) continue;

        visited[node] = 1;
        sum += wt;

        for(auto &edge : adj[node]) {
            int adjNode = edge.first;
            int edgeWt = edge.second;

            if(!visited[adjNode]) {
                pq.push({edgeWt, adjNode});
            }
        }
    }

    return sum;
}

int main(){
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,2});
    adj[1].push_back({0,2});

    adj[0].push_back({3,6});
    adj[3].push_back({0,6});

    adj[1].push_back({2,3});
    adj[2].push_back({1,3});

    adj[1].push_back({3,8});
    adj[3].push_back({1,8});

    adj[1].push_back({4,5});
    adj[4].push_back({1,5});

    adj[2].push_back({4,7});
    adj[4].push_back({2,7});

    cout << "MST Weight: " << prims(V, adj);
}