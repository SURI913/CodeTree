#include <iostream>

using namespace std;

int n;
int A[10][10];
int visited[10];
int result = 987654321;

void BackTracking(int current, int count, int sum){

    if(count == n){
        if(A[current][0] == 0){
            return;
        }
        //선택 끝
        if(result > sum+A[current][0]) result = sum+A[current][0];
        return;
    }

    for (int next = 0; next < n; next++){

        if(visited[next]) continue;
        if (A[current][next] == 0) continue;
        visited[next] = true;
        //cout << sum+A[r][i] <<endl;
        BackTracking(next,count+1,sum+A[current][next]);
        visited[next] = false;

    }
    
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    visited[0] = true;
    BackTracking(0,1,0);
    cout << result <<endl;
    // Please write your code here.

    return 0;
}
