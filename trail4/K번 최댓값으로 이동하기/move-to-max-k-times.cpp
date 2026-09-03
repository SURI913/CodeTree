#include <iostream>
#include <utility>
#include <queue>


using namespace std;

int n, k;
int grid[100][100];
int r, c;

int dx[4] ={0,1,0,-1,};
int dy[4] = {1,0,-1,0};

bool IsRange(int x, int y){
    return (x >=0 && x< n && y >=0 && y<n);
}

pair<int,int> BFS(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});

    bool visited[100][100] ={false,};
    visited[y][x] = true;

    int cy,cx;
    int bestRow =y, bestCol=x, bestValue=0;

    while(!q.empty()){
        pair<int,int> currnet = q.front();
        cy = currnet.first;
        cx = currnet.second;
        q.pop();

        for(int i=0; i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];


            if(IsRange(nx, ny) && !visited[ny][nx] && grid[ny][nx] < grid[y][x]){

                visited[ny][nx] = true;
                q.push({ny,nx});

                if (grid[ny][nx] > bestValue) {
                    // 갱신
                    bestRow = ny;
                    bestCol = nx;
                    bestValue = grid[ny][nx];
                }
                else if (grid[ny][nx] == bestValue) {
                    if (ny < bestRow) {
                        // 갱신
                        bestCol = nx;
                        bestRow = ny;
                    }
                    else if (ny == bestRow && nx < bestCol) {
                        // 갱신
                        bestCol = nx;
                        bestRow = ny;
                    }
                }
            }
        }
        
    }

    return {bestRow,bestCol};
}



int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    pair<int,int> result = BFS(r-1,c-1);

    for(int i =1; i <k; i++){
        result = BFS(result.first,result.second);
    }

    cout << result.first+1 <<" " << result.second+1 << endl;

    return 0;
}
