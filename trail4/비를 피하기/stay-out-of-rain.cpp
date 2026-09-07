#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100

int n, h, m;
int grid[MAX][MAX];

vector<pair<int, int>> M;
int dist[MAX][MAX];
int answer[MAX][MAX];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void BFS() {
    queue<pair<int, int>> q;
    int visited[MAX][MAX] = {false,};

    for (int i = 0; i < m; i++) {
        q.push(M[i]);
        visited[M[i].first][M[i].second] = true;
    }

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (!IsRange(nr, nc) || visited[nr][nc]) continue; //이동 불가능 한 범위
            if (grid[nr][nc] == 1) continue; //벽있음

            //외에는 이동 다 가능
            visited[nr][nc] = true;
            dist[nr][nc] = dist[cr][cc] + 1; //한칸 움직이는데 1초
            q.push({nr, nc});
        }
    }
}

int main() {
    cin >> n >> h >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            //사람을 기준으로 찾는게 아니라 비를 피할 수 잇는공간부터
            //사람에게까지 가는 거리를 계산해야지, 최단거리는 BFS가 해주니까
            //공간부터 최단거리를 탐색하면 자연스럽게 사람이 있는 거리까지 알 수 있음
            //이러면 출력떄도 다른거 없이 그리드 값이 2일때 dist에 있는 값을 꺼내고
            //아닐떄는 0을 출력하면 끝
            if (grid[i][j] == 3) {
                M.push_back({i, j});
            }
        }
    }

    BFS();

    //dist랑 사람 좌표를 보고 출력 처리

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if(grid[i][j]==2 && dist[i][j] == 0) cout << -1 << ' ';
            else if (grid[i][j]==2) cout << dist[i][j] << ' ';
            else cout << 0 << ' ';
        }
        cout << endl;
    }
    // Please write your code here.

    return 0;
}
