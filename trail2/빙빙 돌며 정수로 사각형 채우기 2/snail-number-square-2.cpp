#include <iostream>

using namespace std;

int n, m;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int arr[100][100];

bool IsRange(int x, int y){
    return (x>=0 && x<m && y>=0 && y<n);
}

int main() {
    cin >> n >> m;
    int x =0, y=0;
    int dir =0;

    for(int i =1; i <= n*m; i++){
        arr[y][x] = i;

        int nx = x+dx[dir];
        int ny = y+dy[dir];

        if(!IsRange(nx,ny) || arr[ny][nx]!=0){
            dir = (dir+1)%4;
        }
        
        x = x+dx[dir];
        y = y+dy[dir];
    }

    // Please write your code here.
    for(int i =0; i <n; i++){
        for(int j=0; j<m ;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
