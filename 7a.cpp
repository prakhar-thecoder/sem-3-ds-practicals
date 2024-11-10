#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 5;
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][2] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[2][3] = 1;
    adjMatrix[3][4] = 1;
    adjMatrix[4][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
