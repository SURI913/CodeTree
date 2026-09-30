#include <iostream>

using namespace std;

int n, k;
int arr[1000];
int prefixSum[1000];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    }
    
    int cnt = 0;
    //앞에 [1]이 k인지 확인해봐?
    if(prefixSum[1] == k) cnt++;
    // 두개씩만이 아니라 
    for (int i = 2; i < n; i++) {
        int sumA = prefixSum[i] - prefixSum[i - 2];
        int sumB = prefixSum[i] - prefixSum[i - 1];
        if (sumA == k || sumB == k) {
            cnt++;
        }

        //if(prefixSum[i] == k) cnt++;
    }

    // Please write your code here.
    cout << cnt << endl;

    return 0;
}

//1 2 1 3
//1 3 4 7
//[0][0+1][1+2-0][]
