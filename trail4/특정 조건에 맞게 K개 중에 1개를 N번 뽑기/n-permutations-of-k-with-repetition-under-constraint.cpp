#include <iostream>

using namespace std;

int K, N;

int visited[5]; //k=4
int arr[8]; //8

void choice (int count){

    if(count == N){
        for(int i = 0; i< N; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i<= K; i++){

        if(count >= 2){
            if(arr[count-2] == arr[count-1] 
            && arr[count-1] == i ) continue;

        }
        arr[count] = i;
        choice(count+1);
    }
}

int main() {
    cin >> K >> N;

    choice(0);
    // Please write your code here.

    return 0;
}
