#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string word1;
string word2;

int main() {
    cin >> word1;
    cin >> word2;

    // Please write your code here.

    if(word1.size() != word2.size()){
        cout << "No" <<endl;
        return 0;
    }

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    bool isEqual = true;
    for(int i =0; i< word1.size(); i++){
        if(word1[i]!=word2[i]){
            isEqual = false;
            break;
        }
    }
        
    if(isEqual) cout << "Yes" <<endl;
    else cout << "No" <<endl;

    return 0;
}
