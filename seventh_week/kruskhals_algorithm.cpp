#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
};


bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent, parent[vertex]);
}


void unionSets(int parent[], int rank[], int u, int v) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if (u == v)
        return;

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}


void kruskal(vector<Edge>& edges, int V) {

    
    sort(edges.begin(), edges.end(), compare);

    int parent[V];
    int rank[V];

    
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    int edgeCount = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";


    for (Edge edge : edges) {

        int u = findParent(parent, edge.src);
        int v = findParent(parent, edge.dest);

        if (u != v) {

            cout << char('a' + edge.src)
                 << " - "
                 << char('a' + edge.dest)
                 << "\t"
                 << edge.weight << endl;

            totalWeight += edge.weight;

            unionSets(parent, rank, u, v);

            edgeCount++;

        
            if (edgeCount == V - 1)
                break;
        }
    }

    if (edgeCount != V - 1) {
        cout << "MST does not exist. Graph is disconnected.\n";
        return;
    }

    cout << "Total Weight = " << totalWeight << endl;
}

int main() {

    int V = 9;

    vector<Edge> edges = {

        {0, 1, 4},   // a-b
        {0, 7, 8},   // a-h
        {1, 2, 8},   // b-c
        {1, 7, 11},  // b-h
        {2, 3, 7},   // c-d
        {2, 6, 4},   // c-g
        {2, 8, 2},   // c-i
        {3, 4, 9},   // d-e
        {3, 5, 14},  // d-f
        {4, 5, 10},  // e-f
        {5, 6, 2},   // f-g
        {6, 7, 1},   // g-h
        {6, 8, 6},   // g-i
        {7, 8, 7}    // h-i
    };

    kruskal(edges, V);

    return 0;
}
