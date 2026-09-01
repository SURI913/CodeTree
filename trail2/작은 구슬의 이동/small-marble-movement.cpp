#include <iostream>

using namespace std;

int n, t;
int r, c;
char d;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,+1,0};

bool InRange(int x, int y){
    return (x > 0 && x <= n && y > 0 && y<=n);
}


int main() {
    cin >> n >> t;
    cin >> r >> c >> d;

    int dir;
    if(d =='U') dir =0;
    else if(d =='R') dir =1;
    else if(d =='D') dir =2;
    else if(d =='L') dir =3;

    // d가 방향 나타냄
    for(int i =0; i<t; i++){
        int nx = c+ dx[dir];
        int ny = r+ dy[dir];
        if(InRange(nx,ny)){
            c = nx;
            r = ny;
        }
        else{
            //벽에서 만나면 회전
            dir = (dir+2)%4;
        }
    }

    cout << r <<' '<< c;

    return 0;
}