#include <iostream>
#include <string>

using namespace std;

int N, T;
string str;
int board[100][100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int visited[100][100];

bool InRange(int x, int y){
    return (x >= 0 && x<N && y>=0&& y<N);
}

int main() {
    cin >> N >> T;
    cin >> str;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int check = T;
    int result =0, x,y;
    x =y = N/2;
    int dir =1; //북쪽봐야지 방향치가
    result += board[y][x];
    for(int check =0; check < T; check++){
        

        if(str[check] == 'R') dir = (dir+3)%4;
        else if(str[check] == 'L') dir = (dir+1)%4;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(InRange(nx,ny)&&str[check] == 'F'){
            visited[ny][nx]= true;
            x = nx;
            y = ny;
            result += board[y][x];
        }
    }
    cout << result <<endl;

    return 0;
}