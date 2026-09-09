#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int grid[200][200];
int result;


//모양 정함
int blocks[6][3][3] ={
    {
        {1,0,0},
        {1,1,0},
        {0,0,0},
    },
    {
        {1,1,0},
        {0,1,0},
        {0,0,0},
    },
    {
        {0,1,0},
        {1,1,0},
        {0,0,0},
    },
    {
        {1,1,0},
        {1,0,0},
        {0,0,0},
    },
    {
        {1,1,1},
        {0,0,0},
        {0,0,0},
    },
    {
        {1,0,0},
        {1,0,0},
        {1,0,0},
    },
};

bool IsRange(int r, int c){
    return (r >=0 && r<n && c >=0 && c<m);
}

void Seach(int r, int c){
    for(int k =0; k < 6; k++){
        int sum =0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(IsRange(r+i, c+j) && blocks[k][i][j] == 1){
                    //범위안에 있다면 값 더함
                    sum += grid[r+i][c+j];
                }
            }
        }
        result = max(result, sum);
    }
    return;
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Seach(i, j);
        }
    }


    // Please write your code here.
    cout << result <<endl;

    return 0;
}
