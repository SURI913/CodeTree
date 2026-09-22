#include <iostream>

using namespace std;
#define MAX 11

int N, M;
int visited[MAX];
int arr[MAX];

void Seach(int count, int start){

    if(count == M){
        for(int i =0; i< M; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = start; i<= N; i++){
        if(visited[i]) continue;

        visited[i] = true;
        arr[count] = i;
        Seach(count+1, i);
        visited[i] = false;
        
    }

}

int main() {
    cin >> N >> M;

    // Please write your code here.
    Seach(0,1);

    return 0;
}
