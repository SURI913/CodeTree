#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, k;
int grid[100][100];
int r[10000], c[10000];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int BFS() {
    queue<pair<int, int>> q;
    int visited[100][100] = {false,};

    for (int i = 0; i < k; i++) {
        q.push({r[i] - 1, c[i] - 1});
        visited[r[i] - 1][c[i] - 1] = true;
    }

    int cnt = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = current.first + dr[i];
            int nc = current.second + dc[i];

            if (IsRange(nr, nc) && grid[nr][nc] != 1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});

            }
        }

    }

    return cnt;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    for (int i = 0; i < k; i++) cin >> r[i] >> c[i];
    //k개의 시작점?

    // Please write your code here.

    int result = BFS();
    cout << result << endl;

    return 0;
}
