#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
int visited[9];

void Choice(int count){
    if(count == n){
        for(int i =0; i< n; i++){
            cout << arr[i] <<" ";
        }
        cout <<endl;
        return;
    }

    for(int i =1; i<= n; i++){
        if(visited[i]) continue;

        visited[i] = true;
        arr.push_back(i);
        Choice(count+1);
        arr.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    Choice(0);

    return 0;
}
