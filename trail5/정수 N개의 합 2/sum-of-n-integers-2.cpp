#include <iostream>

using namespace std;

int n, k;
int arr[100000];
int prefixSum[100000];

int main() {
    cin >> n >> k;
    //k개의 원소로 이루어진 수열, 이 중 연속하는 k개의 원소의 합
    //중 가장 큰 값을 구하는 프로그램
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    prefixSum[0] =0;
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1]+arr[i];
    }
    //k개 구간 합 비교
    
    int max = 0;
    for (int i = k; i < n; i++) {
        if(max < prefixSum[i]-prefixSum[i-k]){
            max = prefixSum[i]-prefixSum[i-k];
        }
    }

    cout << max << endl;

    return 0;
}
