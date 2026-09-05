#include <iostream>
#include <vector>

using namespace std;
#define MAX 200

int n;
int grid[MAX][MAX];
vector<int> answer[MAX];
int r, c;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void Bomb(int r, int c) {

    int power = grid[r][c];
    grid[r][c] = 0;
    for (int p = 1; p < power; p++) {
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i] * p;
            int nc = c + dc[i] * p;

            if (!IsRange(nr, nc)) continue;
            //cout << " 0처리 인덱스 값; "<<nr << " "<<nc <<endl;
            grid[nr][nc] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[j][i] != 0) {
                answer[i].push_back(grid[j][i]);
            }
        }
        //입력된 라인의 size만큼 n-size개 0채울 것
        int zeroSize = n - answer[i].size();
        for (int j = zeroSize; j > 0; j--) {
            answer[i].push_back(0);
        }
    }
    //출력때 돌려서 해야하는거 잊지말자

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    Bomb(r-1, c-1);

    // Please write your code here.
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j <n; j++) {
            cout << answer[j][i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
