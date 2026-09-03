#include <iostream>
#include <queue>
#include <utility>
#define MAX 100

using namespace std;

int n, m;
int a[MAX][MAX];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool IsRange(int x, int y){
    return (y >=0 && y <n&& x>=0 && x<m);
}

int BFS(int x, int y){
    queue<pair<int,int>> q;
    bool visited[MAX][MAX]={false,};
    q.push({x,y});
    visited[y][x] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(cx == m-1 && cy == n-1){
            return 1;
        }

        for(int i =0; i< 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(IsRange(nx,ny) && a[ny][nx] == 1 && !visited[ny][nx]){
                //이동가능
                visited[ny][nx] = true;
                q.push({nx,ny});
            }
        }
    }

    return 0;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int result = BFS(0,0);
    cout << result <<endl;
    // Please write your code here.

    return 0;
}
