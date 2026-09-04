#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int n, k, m;
int grid[100][100];
int r[10000], c[10000];

int dr[4] ={0,1,0,-1};
int dc[4] ={1,0,-1,0};

vector<pair<int,int>> rocks;
int answer;


bool IsRange(int x, int y){
    return (x >=0 && x<n && y>=0&&y<n);
}

void BFS(){
    queue<pair<int,int>> q;
    int visit[100][100] ={false,};
    int cnt = 0;

    for(int i=0; i<k; i++){
        q.push({r[i],c[i]});
        visit[r[i]][c[i]] =true;
        cnt++;
    }

    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i =0; i<4; i++){
            int nr= cr + dr[i];
            int nc = cc+ dc[i];

            if(!IsRange(nr,nc)) continue;
            if(visit[nr][nc]) continue;
            if(grid[nr][nc] == 1 ) continue;

            q.push({nr, nc});
            visit[nr][nc]= true;
            cnt++;
        }
    }
    answer = max(answer, cnt);
    return;
}

void DFS(int start, int count){
    if(count == m){
        //조합 선택 완료
        BFS();
        return;
    }

    for(int i =start; i <rocks.size(); i++ ){
        int y = rocks[i].first;
        int x = rocks[i].second;

        grid[y][x] =0;
        DFS(i+1, count+1);
        grid[y][x] =1;
    }

}



int main() {
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                rocks.push_back({i,j});
            }
        }

    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }

    DFS(0,0);
    // Please write your code here.
    cout << answer << endl;

    return 0;
}
