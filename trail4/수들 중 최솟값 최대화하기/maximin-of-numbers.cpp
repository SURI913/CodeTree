#include <iostream>
#include <vector>

using namespace std;

int n;
int grid[10][10];
int visited[10];
vector<int> choice;

int result;

void BackTracking(int r){

    if(r == n){
        int min = 987654321;
        for(int item : choice){
            if(min > item) min = item;
        }
        //선택 완료

        if(result < min) result = min;
        //최솟값중 최대인 수 찾기
        return;
    }

    for(int c =0; c <n; c++){
        if(visited[c]) continue;

        choice.push_back(grid[r][c]);
        visited[c] = true;
        BackTracking(r+1);
        visited[c] = false;
        choice.pop_back();
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    BackTracking(0);
    cout << result << endl;
    // Please write your code here.

    return 0;
}
