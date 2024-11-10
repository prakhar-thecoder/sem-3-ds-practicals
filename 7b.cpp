#include <bits/stdc++.h>
using namespace std;

const int n = 5;
vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
vector<bool> visited(n, false);

void dfs(int node) {
    cout << "Department " << char('A' + node) << " ";
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    fill(visited.begin(), visited.end(), false);
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Department " << char('A' + node) << " ";
        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void shortestPath(int start, int end) {
    queue<int> q;
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (adjMatrix[node][i] && dist[i] == -1) {
                q.push(i);
                dist[i] = dist[node] + 1;
                parent[i] = node;
            }
        }
    }

    if (dist[end] == -1) {
        cout << "No path from Department " << char('A' + start) << " to Department " << char('A' + end) << endl;
    } else {
        cout << "Shortest path: ";
        vector<int> path;
        for (int at = end; at != -1; at = parent[at])
            path.push_back(at);
        reverse(path.begin(), path.end());
        for (int i : path)
            cout << "Department " << char('A' + i) << " ";
        cout << "\nDistance: " << dist[end] << endl;
    }
}

int main() {
    adjMatrix[0][1] = 1; adjMatrix[0][2] = 1;
    adjMatrix[1][2] = 1; adjMatrix[1][3] = 1;
    adjMatrix[2][3] = 1; adjMatrix[3][4] = 1;
    adjMatrix[4][0] = 1;

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDFS starting from Department A: ";
    fill(visited.begin(), visited.end(), false);
    dfs(0);

    cout << "\n\nBFS starting from Department A: ";
    bfs(0);

    cout << "\n\nShortest path from Department A to Department D: ";
    shortestPath(0, 3);

    return 0;
}
