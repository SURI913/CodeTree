#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool InRange(int x, int y){
    return (x >= 0 && x < 100 && y >= 0 && y < 100 );
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result =0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int cnt=0;
            for(int dir = 0; dir < 4; dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];
                if(InRange(nx,ny) && grid[ny][nx]== 1) cnt++;
            }
            if(cnt >= 3) result++;
        
        }
    }

    cout << result <<endl;

    return 0;
}