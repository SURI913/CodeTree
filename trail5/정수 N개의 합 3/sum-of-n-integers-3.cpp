#include <iostream>

using namespace std;

int n, k;
int arr[500][500];
int prefixSum[501][501];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    for( int i = 1; i<=n; i++){
        for(int j =1; j<=n; j++){
            prefixSum[i][j] = prefixSum[i-1][j]+prefixSum[i][j-1]-prefixSum[i-1][j-1] + arr[i-1][j-1];
        }
    }

    int max = 0;
    for( int i = k; i<=n; i++){
        for(int j =k; j<=n; j++){
            int cal = prefixSum[i][j]-prefixSum[i-k][j]-prefixSum[i][j-k]+prefixSum[i-k][j-k];
            if(max < cal){
                max = cal;
            }
        }
    }

    // Please write your code here.
    cout << max <<endl;

    return 0;
}
