#include <iostream>
#include <climits>
using namespace std;

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int V;


int findMinKey(int key[], bool mstSet[]) {
    int min = INF;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}


void primMST(int start) {

    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];


    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[start] = 0;

    
    for (int count = 0; count < V; count++) {

        int u = findMinKey(key, mstSet);

        
        if (u == -1) {
            cout << "MST does not exist. Graph is disconnected.\n";
            return;
        }

        mstSet[u] = true;

        
        for (int v = 0; v < V; v++) {

            if (graph[u][v] != INF &&
                !mstSet[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }


    int totalWeight = 0;

    cout << "\nMinimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 0; i < V; i++) {

        if (i == start)
            continue;

        cout << char('a' + parent[i])
             << " - "
             << char('a' + i)
             << "\t"
             << graph[parent[i]][i]
             << endl;

        totalWeight += graph[parent[i]][i];
    }

    cout << "Total Weight = " << totalWeight << endl;
}

int main() {

    V = 9;

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {

            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    
    graph[0][1] = graph[1][0] = 4;
    graph[0][7] = graph[7][0] = 8;
    graph[1][2] = graph[2][1] = 8;
    graph[1][7] = graph[7][1] = 11;
    graph[2][3] = graph[3][2] = 7;
    graph[2][6] = graph[6][2] = 4;
    graph[2][8] = graph[8][2] = 2;
    graph[3][4] = graph[4][3] = 9;
    graph[3][5] = graph[5][3] = 14;
    graph[4][5] = graph[5][4] = 10;
    graph[5][6] = graph[6][5] = 2;
    graph[6][7] = graph[7][6] = 1;
    graph[6][8] = graph[8][6] = 6;
    graph[7][8] = graph[8][7] = 7;

    // Start from vertex 'a'
    primMST(0);
    
    primMST(3);

    return 0;
}
