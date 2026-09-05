#include <iostream>

using namespace std;

int n, m;
int grid[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if(m ==1){
        cout << n*2 << endl;
        return 0;
    }

    int answer=0;

    for(int i =0; i< n; i++){
        int cntr =1, cntc = 1;
        bool checkr=false, checkc=false;
        
        for(int j=0; j<n-1; j++){
            if(grid[i][j] == grid[i][j+1])cntr++;
            else cntr=1;
            if(grid[j][i] == grid[j+1][i])cntc++;
            else cntc=1;

            if (cntr >= m && !checkr) {
                answer++;
                checkr = true;
            }

            if (cntc >= m && !checkc) {
                answer++;
                checkc = true;
            }
        }

    }

    // Please write your code here.
    cout << answer <<endl;
    return 0;
}
