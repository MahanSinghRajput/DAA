DIJKSTRA(G, source)

Input:
    G = Graph with vertices V and edges E
    source = starting vertex

Output:
    dist[v] = shortest distance from source to each vertex v

1. for each vertex v in V:
2.       dist[v] ← ∞
3.       prev[v] ← NULL
4.       visited[v] ← false

5. dist[source] ← 0

6. for i ← 1 to |V|:
7.       u ← vertex with minimum dist[u] among unvisited vertices
8.       visited[u] ← true

9.       for each neighbor v of u:
10.            if visited[v] = false AND dist[u] + weight(u,v) < dist[v]:
11.                    dist[v] ← dist[u] + weight(u,v)
12.                    prev[v] ← u

13. return dist, prev