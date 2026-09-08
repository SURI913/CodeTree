#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x1, x2;

int line[101];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;

        for (int j = x1; j <= x2; j++) {
            line[j]++;
        }
    }

    int result = *max_element(line,line+101);

    cout << result << endl;
    // Please write your code here.

    return 0;
}
