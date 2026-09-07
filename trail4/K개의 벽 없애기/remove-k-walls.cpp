#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100
#define INF 987654321

int n, k;
int grid[MAX][MAX];
int r1, c1, r2, c2;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int answer = INF;

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void BFS() {
    queue<pair<int, int>> q;
    bool visited[MAX][MAX] = {false,};
    int dist[MAX][MAX] = {0,};

    q.push({r1, c1});
    visited[r1][c1] = true;

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!IsRange(nr, nc) || visited[nr][nc]) continue;
            if (grid[nr][nc] == 1) continue;

            visited[nr][nc] = true;
            dist[nr][nc] = dist[cr][cc] + 1;
            q.push({nr, nc});
        }
    }
    if (visited[r2][c2]) answer = min(dist[r2][c2], answer);

}

void DFS(int start, int count) {
    if (count == k) {
        BFS();
        return;
    }

    for (int i = start; i < n * n; i++) {
        int r = i / n;
        int c = i % n;

        if (grid[r][c] == 1) {
            grid[r][c] = 0;
            DFS(i + 1, count + 1);
            grid[r][c] = 1;
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    r1--;
    c1--;
    r2--;
    c2--;

    DFS(0, 0);

    cout << (answer == INF ? -1 : answer) << endl;

    // Please write your code here.

    return 0;
}
