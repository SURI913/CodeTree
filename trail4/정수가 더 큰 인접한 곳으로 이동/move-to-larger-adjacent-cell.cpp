#include <iostream>
#include <vector>

using namespace std;

int n;
int r, c;
int a[101][101];

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

bool IsRange(int r, int c){
    return (r >= 1 && r<=n && c>=1 && c<=n);
}

int main() {
    cin >> n >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> answer;
    answer.push_back(a[r][c]);
    while(true){

        int dir = -1;

        for(int i =0; i<4; i++){
            int nr = r +dr[i];
            int nc = c + dc[i];

            if(!IsRange(nr, nc)) continue;
            if(a[nr][nc] > a[r][c]) {
                dir = i;
                break;
            }
        }
        if(dir == -1){
            break;
        }
        r += dr[dir];
        c += dc[dir];
        answer.push_back(a[r][c]);
        
        
    }

    // Please write your code here.
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] <<' ';
    }

    return 0;
}