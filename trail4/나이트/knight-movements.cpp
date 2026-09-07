#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define MAX 100

int n;
int r1, c1, r2, c2;

int dr[8] = {-1,-2,-2,-1,1,2,2,1};
int dc[8] = {-2,-1,1,2,-2,-1,1,2};

int dist[MAX][MAX] = {0,};

bool InRange(int r, int c){
    return (r >=0 && r < n && c>=0 && c<n);
}

int BFS(int r1, int c1, int r2, int c2){
    queue<pair<int,int>> q;
    bool visited[MAX][MAX] = {false,};

    q.push({r1,c1});
    visited[r1][c1] = true;

    if(r1 == r2 && c1 == c2) return 0;

    while (!q.empty()) {
        //탐색
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nr = cr+dr[i];
            int nc = cc+dc[i];

            if(InRange(nr,nc) && !visited[nr][nc]){
                visited[nr][nc] = true;
                dist[nr][nc] = dist[cr][cc]+1;
                q.push({nr,nc});
            }
        }
    }
    
    if(dist[r2][c2] == 0) return -1;
    return dist[r2][c2];
}

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    int result =  BFS(r1-1,c1-1,r2-1,c2-1);
    

    cout << result <<endl;

    // Please write your code here.

    return 0;
}
