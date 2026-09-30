#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, k;
string t;
string str[100];

int main() {
    cin >> n >> k >> t;

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    // Please write your code here.

    sort(str, str + n);

    //t의 앞을기즌으로 시작점 잡고 찾으면 되나
    int start = 'z'-'a';
    if(start > (int)t[0]-'a') start = 0;
    else start = n-1;

    //여기서 이제 똑같이 시작하는 애들 중에서 고르기

    int idx = 0;

    while (true) {

        if(str[start][idx] != t[idx]){
            //cout << "안맞음 str: " << str[start][idx] << " t: " << t[idx] <<endl;

            start++;
        }
        else{

            //cout << "맞음 str: " << str[start][idx] << " t: " << t[idx] <<endl;

            idx++;
        }
        
        if(idx == t.size()){
            //개행문자 만나면 끝
            //여기서부터 K번째세야함 
            break;
        }
        
    }

    cout << str[start+k-1] <<endl;
    

    return 0;
}
