#include <iostream>
#include <vector>

using namespace std;

int n; //블록 수 
vector<int> blocks;//블록보관
int s1, e1; //1번째로 제거할 블록정보
int s2, e2; //두번째로 제거할 블록 정보

vector<int> SetJenga(int start, int end){
    vector<int> tmp;

    for(int i =0; i<blocks.size(); i++){
        //start부터 end까지의 값 제외하고 저장
        if(i < start){
            tmp.push_back(blocks[i]);
        }
        else if(i > end){
            tmp.push_back(blocks[i]);
        }
    }

    return tmp;
}

int main() {
    cin >> n;
    blocks.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    blocks = SetJenga(s1-1, e1-1);
    blocks = SetJenga(s2-1, e2-1);

    // Please write your code here
    
    cout << blocks.size() << '\n';

    for(int i =0; i< blocks.size(); i++){
        cout << blocks[i] << endl;
    }

    return 0;
}
