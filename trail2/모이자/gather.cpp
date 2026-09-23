#include <iostream>

using namespace std;

int n;
int A[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int min =987654321;

    for(int here=1; here<=n; here++){
        int sum =0;
        for(int j=1; j<=n; j++){
            sum += A[j-1]*(abs(j-here));
        }
        if(min > sum){
            min = sum;
        }
    }

    // Please write your code here.
    cout << min << endl;
    return 0;
}