#include <iostream>
#include <deque>

using namespace std;

int n, m, q;
deque<int> blocks[100];

void Push(int r, char d) {
    if (d == 'L') {
        int tmp = blocks[r].back();
        blocks[r].pop_back();
        blocks[r].push_front(tmp);
    }
    else {
        int tmp = blocks[r].front();
        blocks[r].pop_front();
        blocks[r].push_back(tmp);
    }
}

char Check(int main, int other, char d) {
    bool check = false;
    for (int k = 0; k < m; k++) {
        if (blocks[main][k] == blocks[other][k]){
            check = true;
            break;
        } //아래위러
        //같은 숫자 영향
    }
    if (!check) return 'N'; //같은거 없으면 끝
    if (d == 'L') return 'R';
    else return 'L';
    //빈대방향으로 영향이 감
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            blocks[i].push_back(input);
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        Push(r - 1, d);
        char prv_d = d;

        //윗 행 영향체크
        for (int j = r - 1; j > 0; j--) {
            prv_d = Check(j, j - 1, prv_d);
            if (prv_d == 'N') break;
            Push(j - 1, prv_d); //인근 반대로 위치 전파
        }

        prv_d = d;
        //아래 행 영향체크
        for (int j = r; j < n; j++) {
            prv_d = Check(j -1, j, prv_d);
            if (prv_d == 'N') break;
            Push(j, prv_d); //인근 반대로 위치 전파
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << blocks[i][j] << ' ';
        }
        cout << '\n';
    }

    // Please write your code here.

    return 0;
}
