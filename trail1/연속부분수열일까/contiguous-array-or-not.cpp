#include <iostream>
#include<vector>

using namespace std;
int A[100];
int B[100];
int a,b;


int main() {

    cin >> a >> b;

    for(int i =0; i <a; i++){
        cin >> A[i];
    }
    for(int i =0; i <b; i++){
        cin >> B[i];
    }

    bool check;
    for(int i=0; i <=a-b; i++){
        check = true;
        for(int j =0; j<b; j++){
            if(A[i+j] != B[j]){
                check = false;
                break;
            }
        }

        if(check){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    cout << "No" <<endl;
    return 0;
}