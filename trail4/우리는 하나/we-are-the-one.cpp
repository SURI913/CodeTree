#include <iostream>
#include <queue>
#include <utility>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, u, d;
int grid[8][8];
vector<pair<int,int>> selected;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int answer;

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void BFS() {
    queue<pair<int, int>> q;
    bool visited[8][8]={false,}; //초기화 까먹지마라
    int cnt =0;
    for(int i =0; i< selected.size(); i++){
        pair<int, int> pos = selected[i];
        q.push(pos);
        visited[pos.first][pos.second] = true;
        cnt++;
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop(); //꺼내는것도 잊지마라

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i]; //변수명 잘봐라

            if (!IsRange(nr, nc) || visited[nr][nc]) continue;

            int diff = abs(grid[r][c] - grid[nr][nc]); //절대값이어야 한다

            if(diff>=u && diff<=d){
                //이동 가능한 범위
                q.push({nr, nc});
                visited[nr][nc] = true;
                cnt++;
            }

        }
    }
    answer = max(cnt, answer);
}

void DFS(int start,int count){
    if(count == k){
        BFS();
        return; //BFS 시작하고 바로 함수 끝내야하는거 잊지말자
    }


    for(int i = start; i < n*n; i++){
        int r = i / n;
        int c = i % n;

        selected.push_back({r,c});
        DFS(i+1,count+1);
        selected.pop_back();
    }
    
}

int main() {
    cin >> n >> k >> u >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    DFS(0,0);
    //DFS로 K개 도시 선정 후 선정된 도시로 BFS
    //BFS(0, 0);
    // Please write your code here.
    cout << answer <<endl;
    return 0;
}
