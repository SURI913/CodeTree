#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

int n, m, k;
int grid[100][100];


//테트리스?


int main() {
    cin >> n >> m >> k; // 격자크기, 블록크기, 떨어지는 위치

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    //블럭은  i*m
    int min=100;
    for (int i = k-1; i < k-1+m && i < n; i++) { //k위치부터 높은 높이 찾기
        int h=n;
        for (int j = 0; j < n; j++) { //격자안 블록 높이 계산
            if(grid[(n-1)-j][i] == 1){
                h = (n-1)-j;
            }
        }

        if(h < min){
            //가장 높은 높이 찾자 쌓이는거라작은 값 찾ㅇ아야함
            min = h;
        }
    }

    for (int i = k-1; i < k-1+m && i < n; i++){
        grid[min-1][i] = 1; //그 바로위에 블럭 쌓
    }

    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}
