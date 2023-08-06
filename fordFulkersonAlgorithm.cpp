#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to contract the graph G by merging nodes u and v
vector<vector<int>> contractGraph(vector<vector<int>>& G, int u, int v, int n) {
    // Create a new graph with size (n-1) x (n-1)
    vector<vector<int>> G2(n - 1, vector<int>(n - 1, 0));

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (i != u && i != v) {
            int jdx = 0;
            for (int j = 0; j < n; j++) {
                if (j != u && j != v) {
                    G2[idx][jdx] = G[i][j];
                    jdx++;
                }
            }
            idx++;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (i >= j) {
                G2[i][j] = G2[j][i];
            }
        }
    }

    return G2;
}

int minCut(vector<vector<int>>& G, int n, vector<vector<int>>& edge) {
    if (n == 2) {
        return G[0][1]; // Base case: return the remaining edge weight
    }

    int val = (rand() % edge.size());
    int u = edge[val][0];
    int v = edge[val][1];

    // Recursively contract the graph G
    vector<vector<int>> contractedGraph = contractGraph(G, u, v, n);

    return minCut(contractedGraph, n - 1, edge);
}

int main() {
    srand(time(0));

    int n;
    cout << "enter the number of vertices: " << endl;
    cin >> n;
    vector<vector<int>> G(n, vector<int>(n, 0));

    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            G[i][j] = temp;
        }
    }

    vector<vector<int>> edge = { {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4} };
    cout << minCut(G, n, edge) << endl;

    return 0;
}
