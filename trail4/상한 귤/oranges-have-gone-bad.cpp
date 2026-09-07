#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
#define MAX 100

int n, k;
int grid[MAX][MAX];

vector<pair<int,int>> selected;
int dist[MAX][MAX];

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

bool IsRange(int r, int c){
    return (r >=0 && r<n && c >= 0 && c<n);
}

void BFS(){
    queue<pair<int,int>> q;
    bool visited[MAX][MAX] = {false,};

    for(int i =0; i<selected.size(); i++){
        q.push(selected[i]);
        visited[selected[i].first][selected[i].second] = true;
    }
    
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i =0 ;i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(IsRange(nr,nc) && !visited[nr][nc] && grid[nr][nc] ==1){
                visited[nr][nc] = true;
                dist[nr][nc] = dist[cr][cc] +1;
                q.push({nr,nc});
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 2){
                selected.push_back({i, j});
            }
        }
    }

    // Please write your code here.

    BFS();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int draw;
            if(grid[i][j] == 2) draw =0;
            else if(grid[i][j] == 0) draw = -1;
            else{
                //1일때
                if(dist[i][j] == 0) draw = -2;
                else draw = dist[i][j];
            }

            cout << draw << ' ';
        }
        cout << endl;
    }

    return 0;
}
