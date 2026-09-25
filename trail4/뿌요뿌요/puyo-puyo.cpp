#include <iostream>

using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int cnt;

bool IsRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void DFS(int r, int c) {

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (!IsRange(nr, nc) || visited[nr][nc]) continue;

        if (grid[r][c] == grid[nr][nc]) {
            visited[nr][nc] = true;
            cnt++;
            DFS(nr, nc);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int maxCount = 0;
    int bombCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt = 1;
            if (visited[i][j]) continue;

            visited[i][j] = true;
            DFS(i, j);
            if (cnt > maxCount) {
                maxCount = cnt;
            }
            if(cnt >= 4) bombCount++;

        }
    }

    // Please write your code here.
    cout << bombCount << " " << maxCount << endl;

    return 0;
}
