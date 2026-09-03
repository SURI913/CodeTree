#include <iostream>
#include <vector>


using namespace std;

int n;
int answer;

vector<int> arr;

bool Check(){
    for(int i=0; i<n;i+=arr[i]){
        for(int j=i; j<i+arr[i];j++){
            if(arr[i]!= arr[j]) return false;
        }
    }

    return true;
}

void Select(int count){
    if(count == n){
        if(Check()) answer++;
        return;
    }
    
    for(int i =1; i<=4;i++){
        arr.push_back(i);
        Select(count+1);
        arr.pop_back();
    }
}

int main() {
    cin >> n;

    // Please write your code here.
    Select(0);

    cout << answer <<endl;
    return 0;
}
