#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int grid[25][25];
int visited[25][25];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

priority_queue<int, vector<int>, greater<int>> pq;
int cnt;

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void DFS(int r, int c) {

    for (int i = 0; i < 4; i++) {
        int nr = dr[i] + r;
        int nc = dc[i] + c;

        if (!IsRange(nr, nc) || visited[nr][nc]) continue;

        if (grid[nr][nc] > 0) {
            visited[nr][nc] = true;
            //cout << pq.size() << "번째 확인 중 :" <<
            //nr << " " << nc << "좌표 방문 처리 완료!" <<endl;
            cnt += grid[nr][nc];
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 0 && !visited[i][j]) {
                visited[i][j] = true;
                cnt += grid[i][j];

                DFS(i, j);

                // cout << pq.size()+1 << "번째 확인 중 :" <<
                // i << " " << j << "좌표 DFS 호출했습니다" <<endl;

                if (cnt > 0) {
                    pq.push(cnt);
                    cnt = 0;
                }
            }
        }
    }

    // Please write your code here.

    cout << pq.size() << endl;
    while (!pq.empty()) {
        int item = pq.top();
        pq.pop();

        cout << item << endl;
    }

    return 0;
}
