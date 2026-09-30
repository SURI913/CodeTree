#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i % 2 == 0) continue;
        sort(arr, arr+i);
        int mid = i/2;
        cout << arr[mid] << " ";
    }

    sort(arr, arr+n);
    int mid = n/2;
    cout << arr[mid] << endl;


    // Please write your code here.

    return 0;
}