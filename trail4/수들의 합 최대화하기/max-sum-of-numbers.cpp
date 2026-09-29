#include <iostream>

using namespace std;

int n;
int grid[10][10];
int visited[10];

int result;

void BackTracking(int r, int sum){

    if(r == n){
        //모두 선택 완료
        if(result < sum){
            result = sum;
        }
        return;
    }

    for(int c =0; c<n; c++){
        if(visited[c]) continue; //같은 열은 스킵, 이미 선택된 열도 안되는데
        visited[c] = true;
        BackTracking(r+1, sum+grid[r][c]);
        visited[c] = false;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    BackTracking(0,0);
    cout << result <<endl;

    return 0;
}
