#include <iostream>

using namespace std;

int n;
int grid[100][100];

int dx[4] ={-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool IsRange(int x, int y){
    return(x >=0 && x<n && y>=0 &&y<n && grid[y][x] == 0);
}

// int main() {
//     cin >> n;
//     int check = n*n;

//     int nx,ny;
//     int x =n/2,y=n/2,dir=0,cnt=0;

//     grid[y][x] = ++cnt;
//     x = x+dx[dir];
//     y = y+dy[dir];

//     while(--check){
//         grid[y][x] = ++cnt;
//         //바라보고있는 방향의 

//         int checkdir = (dir+1)%4;
//         nx = x+dx[checkdir];
//         ny = y+dy[checkdir];
        
//         if(IsRange(nx,ny)){
//             dir = checkdir;
//         }

//         x +=dx[dir];
//         y +=dy[dir];

//     }

//     for(int i =0; i<n;i++){
//         for(int j=0; j<n;j++){
//             cout << grid[i][j]<<" ";
//         }
//         cout << '\n';
//     }
//     // Please write your code here.

//     return 0;
// }

int main() {
    cin >> n;

    int x =n-1,y=n-1,dir=0;

    for(int i = n*n; i>0;i--){
        grid[y][x] = i;

        int nx = x+dx[dir];
        int ny = y+dy[dir];

        if(!IsRange(nx,ny) ||  grid[ny][nx] !=0){
            dir = (dir+1)%4;
        }

        x += dx[dir];
        y += dy[dir];
        
    }

    for(int i =0; i<n;i++){
        for(int j=0; j<n;j++){
            cout << grid[i][j]<<" ";
        }
        cout << '\n';
    }
    // Please write your code here.

    return 0;
}
