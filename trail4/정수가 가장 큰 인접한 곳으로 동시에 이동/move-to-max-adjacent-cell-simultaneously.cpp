#include <iostream>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

int n, m, t;
int a[20][20];
vector<pair<int,int>> rc;
int cnt[20][20];

//m개의 구슬을 동시에 이동 인접한 4 칸중 현재 있는 위치보다 큰 숫자로 동시에
//이동하는거 t번 반복

// 조건 1. 이동할 수 있는 칸 여러개, 상하좌우 순으로 우선순위 매겨 이동
// 조건 2. 이동했는데 두개이상이 같은 위치에 옴 -> 충돌 처리 == 사라짐
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool IsRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void Move() {
    vector<pair<int, int>> swapPosVal;
    int nextCount[20][20] = {0,};

    for (int i = 0; i < rc.size(); i++) {
        int r,c;
        tie(r,c) = rc[i];
        //깨진 구슬은 넘어감

        pair<int, int> nextPos= {r, c};
        int maxValue = 0;
        
        for (int j = 0; j < 4; j++) {
            
            int nr = r + dr[j];
            int nc = c + dc[j];
            if (!IsRange(nr, nc)) continue;

            if (maxValue < a[nr][nc]) {
                //nextPos변경
                nextPos = {nr, nc};
                maxValue = a[nr][nc];
            }
        }

        swapPosVal.push_back(nextPos);
        nextCount[nextPos.first][nextPos.second]++;
    }

    //동시 움직임 끝 깨진 구슬 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            cnt[i][j] = nextCount[i][j];

            if (cnt[i][j] >= 2) {
                //cout <<  "깨진 구슬 갯수: " << nextCount[i][j]<< endl;
                cnt[i][j] = 0;
            }

            //cout << cnt[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;
    rc.clear();
    //이동할 구슬 처리
    for (int i = 0; i < swapPosVal.size(); i++) {
        if(cnt[swapPosVal[i].first][swapPosVal[i].second] == 0) continue;
        rc.push_back(swapPosVal[i]);
        //swap(a[r[i]][c[i]], a[swapPosVal[i].first][swapPosVal[i].second]);
        
    }

}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        rc.push_back({r,c});
        cnt[r][c] = 1; //구슬 시작위치

    }

    while (t--) {
        Move();
    }
    // Please write your code here.
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           result += cnt[i][j];
        }
    }

    cout << rc.size() << endl;

    return 0;
}

