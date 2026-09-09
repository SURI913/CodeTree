#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 200

int n;
int original[MAX][MAX];
vector<int> tmp[MAX];
int r, c;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void Bomb(int r, int c, int copy[][MAX]) {
    int grid[MAX][MAX]={0,};
    
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            grid[i][j] = copy[i][j];
        }
    }

    int power = grid[r][c];
    grid[r][c] = 0;
    for (int p = 1; p < power; p++) {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i] * p;
            int nc = c + dc[i] * p;

            if (!IsRange(nr, nc)) continue;
            //cout << " 0처리 인덱스 값; "<<nr << " "<<nc <<endl;
            grid[nr][nc] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        tmp[i].clear();
        for (int j = n - 1; j >= 0; j--) {
            if (grid[j][i] != 0) {
                tmp[i].push_back(grid[j][i]);
            }
        }
        //입력된 라인의 size만큼 n-size개 0채울 것
        int zeroSize = n - tmp[i].size();
        for (int j = zeroSize; j > 0; j--) {
            tmp[i].push_back(0);
        }
    }

}

int Check(){
    int cnt=0;
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j <n-1; j++) {
            //여기서 탐색
            //가로 탐색해보고 겹치면 check
            if(tmp[i][j] == tmp[i][j+1] && tmp[i][j] != 0){
                cnt++;
            }
            //세로 탐색
            if(tmp[j][i] == tmp[j+1][i] && tmp[j][i] != 0){
                cnt++;
            }
            
        }
    }
    return cnt;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> original[i][j];
        }
    }

    int result=0; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Bomb(i, j, original);
            //주변 탐색해서 더 터르려야
            result = max(Check(), result);
        }

    }

    cout << result<<endl;

    return 0;
}

