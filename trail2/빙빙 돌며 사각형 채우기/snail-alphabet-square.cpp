#include <iostream>
#include <string>

using namespace std;

int n, m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0,-1};

char arr[100][100];

bool IsRange(int x, int y){
    return (x >=0 && x < m && y >=0 && y < n);
}

int main() {
    cin >> n >> m;

    int x =0, y=0, dir=0;
    for(int i = 0; i<n*m;i++){
        arr[y][x] = 'A'+ i % 26;
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(!IsRange(nx, ny) || arr[ny][nx] !=0){
            //범위 에서 벗어나거나 값이 채워졌을때
            dir = (dir +1)%4;
            
        }
        
        x += dx[dir];
        y += dy[dir];
    }

    for(int i = 0; i<n;i++){
        for(int j = 0; j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    // Please write your code here.

    return 0;
}

