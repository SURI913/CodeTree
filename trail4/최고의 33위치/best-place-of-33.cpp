#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;

    for(int i =0; i< N-2; i++){
        for(int j =0; j < N-2 ;j++){
            int sum =0;
            for(int k =0; k<3; k++){
                for( int h=0; h<3;h++){
                    sum += grid[i+k][j+h];
                }
            }

            result = max(sum, result);
        }
    }
    // Please write your code here.

    cout << result <<endl;

    return 0;
}


