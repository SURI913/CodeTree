#include <iostream>
#include <string>

using namespace std;

string A;

int main() {
    cin >> A;

    // Please write your code here.
    int result = 0;
    for(int i =0; i< A.size(); i++){
        int cnt = 0;
        if(A[i] == ')') continue;
        for(int j = i+1; j<A.size(); j++){
            if(A[i] == '(' && A[j]==')'){
                //시작
                cnt++;
            }
        }
        result+=cnt;
    }

    cout << result << endl;

    return 0;
}