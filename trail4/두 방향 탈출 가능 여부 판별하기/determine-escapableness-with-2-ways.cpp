#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int visited[100][100];
int result;

int dr[4] = {0, 1};
int dc[4] = {1, 0};

bool IsRange(int r, int c) {
    return r >= 0 && r < n && c >= 0&& c < m;
}

void DFS(int cr, int cc) {

    if (!IsRange(cr, cc)) return;

    if (visited[cr][cc]) return;

    if (grid[cr][cc] == 0) return;

    if (cr == n - 1 && cc == m - 1) {
        result = 1; //통과 가능
    }

    visited[cr][cc] = true;
    for (int i = 0; i < 2; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        DFS(nr, nc);
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    DFS(0, 0);

    cout << result << endl;

    // Please write your code here.

    return 0;
}
