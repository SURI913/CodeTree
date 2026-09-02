#include <iostream>

using namespace std;

int N, M;
int r, c;

int dr[4]={0,1,-1,0};
int dc[4] ={1,0,0,-1};

int arr[101][101];

bool InRange(int x, int y){
    return (x >= 1 && x <= N && y >= 1 && y <=N);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> r >> c;

        arr[r][c] =1; //칠

        int cnt =0;

        for(int j =0; j < 4; j++){
            int nr = r+dr[j];
            int nc = c+dc[j];

            if(InRange(nr,nc) && arr[nr][nc] == 1) cnt++;
 
        }
        if(cnt ==3) cout << 1 << endl;
        else cout << 0 << endl;
        
    }

    // Please write your code here.

    return 0;
}