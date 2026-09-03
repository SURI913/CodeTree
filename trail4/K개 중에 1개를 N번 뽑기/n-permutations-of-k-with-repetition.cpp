#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> answer;

void PrintAnswer(){
    for(int i=0; i< answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}

void Select(int count){
    if(count == N){
        PrintAnswer();
        return;
    }

    for(int i =1; i<= K; i++){
        answer.push_back(i);
        Select(count+1);
        answer.pop_back();
    }

}

int main() {
    cin >> K >> N;


    Select(0);
    // Please write your code here.

    return 0;
}
