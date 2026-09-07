#include <iostream>
#include<vector>
#include<queue>
#include <utility>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int N, M;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool IsRange(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}

int BFS(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    int visited[MAX][MAX] = {false,};
    int dist[MAX][MAX] = {0,};
    visited[r][c] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = current.first + dr[i];
            int nc = current.second + dc[i];

            if (!IsRange(nr, nc) || visited[nr][nc]) continue;
            if (graph[nr][nc] == 0) continue; //인덱스 값 확인 잘하자

            visited[nr][nc] = true;
            dist[nr][nc] = dist[current.first][current.second] + 1;
            q.push({nr, nc});
        }

    }

    if (dist[N - 1][M - 1] == 0) return -1;
    return dist[N - 1][M - 1];
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int result = BFS(0, 0);
    cout << result << "\n";

    return 0;
}
