#include <iostream>

using namespace std;

int n, m;
int A[20];
int arr[21];
int visited[21];
int maxVal;

void Search(int count, int start) {
    if (count == m) {
        int result = arr[0];
        for (int i = 1; i < m; i++) {
            result ^= arr[i];
        }
        if (maxVal < result) maxVal = result;
        return;
    }

    for (int i = start; i < n; i++) {
        if(visited[i]) continue;
        
        visited[i] = true;
        arr[count] = A[i];
        Search(count+1, i);
        visited[i] = false;

    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Please write your code here.
    Search(0,0);
    cout << maxVal << endl;

    return 0;
}
