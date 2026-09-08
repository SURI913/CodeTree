#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> numbers;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    while (true) {
        //M개 이상 이면 폭탄 터트림
        vector<int> bomb;
        bool exploded = false;
        int i = 0;
        while (i < numbers.size()) {
            // 투포인터
            int j = i + 1;
            while (j < numbers.size() &&
             numbers[i] == numbers[j]) j++;
            
            // 연속 구간 개수
            int cnt = j - i;
            //폭팔한애들은 스킵하고 아닌애들만 저장함
            if (cnt < m) {
                for (int k = i; k < j; k++) {
                    bomb.push_back(numbers[k]);
                }
            }
            else {
                exploded = true;
            }
            i = j; //다음구간 넘겨
        }
        numbers = bomb;
        if (!exploded) break;
    }

    cout << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] <<endl;
    }

    // Please write your code here.

    return 0;
}


