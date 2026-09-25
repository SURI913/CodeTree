#include <iostream>

using namespace std;

int N, M;
int grid[50][50];
int cnt;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool IsRange(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void DFS(int r, int c, int K, int visited[][50]) {
    //연결된 안전지대만 처리
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (!IsRange(nr, nc)) continue;
        if (visited[nr][nc]) continue;
        if (grid[nr][nc] <= K) continue;

        visited[nr][nc] = true;
        DFS(nr, nc, K, visited);
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int kMin = 987654321;
    int cntMax = 0;

    for (int i = 1; i < 101; i++) {
        int visited[50][50] = {false,};
        cnt = 0;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (visited[r][c]) continue;
                if (grid[r][c] <= i) continue; //물에 잠긴구간

                visited[r][c] = true;
                cnt++;
                DFS(r, c, i, visited);
            }
        }

        if (cntMax < cnt) {
            cntMax = cnt;
            kMin = i;
        }
        else if (cntMax == cnt && kMin > i) {
            kMin = i;
        }
    }

    // Please write your code here.
    cout << kMin << " " << cntMax << endl;

    return 0;
}
