#include <iostream>
#include <vector>

using namespace std;

int n, t;
vector<int> u;
vector<int> d;

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        u.push_back(input);
    }

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        d.push_back(input);
    }

    for(int i = 0; i < t; i++){
        vector<int> tmpu;
        vector<int> tmpd;
        tmpu.push_back(d[n-1]);
        for(int j = 1; j < n; j++){
            tmpu.push_back(u[j-1]);
        }
        //뒤집한 숫자인거 고려
        tmpd.push_back(u[n-1]);
        for(int j = 0; j < n-1; j++){
            tmpd.push_back(d[j]);
        }
        u = tmpu;
        d = tmpd;
    }

    for (int i = 0; i < n; i++) cout << u[i]<< " ";
    cout << '\n';
    for (int i = 0; i < n; i++) cout << d[i]<<" ";

    // Please write your code here.

    return 0;
}
