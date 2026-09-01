#include <iostream>

using namespace std;

int n, m;
int arr[100][100];

int dx[4] ={1,0,-1,};
int dy[4] = {0,1, 0, -1};

bool InRange(int x, int y){
    return(x >=0 && x < m && y >= 0 && y <n  && arr[y][x]==0);
}

int main() {
    cin >> n >> m;

    int cnt =0;
    int dir =0;
    int x =0; int y=0;
    int ny, nx;
    for(int i =0; i<n; i++){
        for(int j=0; j <m; j++){
        
            arr[y][x] = ++cnt;

            ny = dy[dir] +y;
            nx = dx[dir] +x;

            if(!InRange(nx,ny)){
                dir = (dir+1)%4;
                //바꾸고 값 반영 x
                ny = dy[dir] +y;
                nx = dx[dir] +x;
            }
            y = ny;
            x = nx;   
        }
    }
    for(int i =0; i<n; i++){
        for(int j=0; j <m; j++){
            cout << arr[i][j] <<' ';
        }
        cout << '\n';
    }

    return 0;
}