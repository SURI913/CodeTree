#include <iostream>

using namespace std;

int n;
char grid[1000][1000];
int k;

//스타트할 방향 .
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool IsRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int Rotate(char c, int dir) {
    if (c == '/') {
        dir = (dir % 2) ? (dir + 3) % 4 : (dir + 1) % 4; //  '/' 상태에서 dir가 짝수면 시계방향
    }
    else {
        // '\\'일때
        dir = (dir % 2) ? (dir + 1) % 4 : (dir + 3) % 4; //  '\\' 상태에서 dir가 짝수면 시계방향
    }

    return dir;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> k;

    int x, y;
    if (k <= n) {
        x = k - 1; y = 0;
    }
    else if (k <= n * 2) {
        x = n - 1; y = k - n - 1;
    }
    else if (k <= n * 3) {
        x = n * 3 - k; y = n - 1;
    }
    else {
        x = 0, y = n * 4 - k;
    }

    int dir = (k - 1) / n; //1~3은 인덱스 0 접근, 4~6은 인덱스 1 ...
    int cnt = 0;
    //k값이 뭔지에 따라 좌표가 결정나야 함
    while (IsRange(x, y)) {

        char state = grid[y][x];
        //방향 전환
        dir = Rotate(state, dir);

        x += dx[dir];
        y += dy[dir];

        cnt++;

    }

    cout << cnt << endl;

    return 0;
}
