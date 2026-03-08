MST - Given a graph with n nodes m edges you need to draw a spanning tree such that the total sum of the weights of each edge are minimum.

Spanning tree - A tree with n nodes and n-1 edges, and each node is reachable from any of the node.

Algorithms for MST - Prim's, Kruskal

# Prim's algo
* Keep a propity-queue (min-heap) add weight, node and parent in it.
* Keep a visited array.
* Keep an ArrayList to store MST nodes and a sum variable to add weights.