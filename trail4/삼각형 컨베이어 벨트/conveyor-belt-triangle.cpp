#include <iostream>
#include <vector>

using namespace std;

int n, t;
vector<int> l;
vector<int> r;
vector<int> d;

void Play( vector<int>& tmp, vector<int> main, int start){
    tmp[0] = start;
    for(int j =1; j<main.size(); j++) tmp[j] = main[j-1];
}

void Print(vector<int>arr){
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
    cout<<'\n';
}

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        l.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        r.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        d.push_back(input);
    }

    // Please write your code here.
    for (int i = 0; i < t; i++){
        vector<int> tmpL(n,0);
        vector<int> tmpR(n,0);
        vector<int> tmpD(n,0);
        Play(tmpL,l, d[n-1]);
        Play(tmpR,r, l[n-1]);
        Play(tmpD,d, r[n-1]);
        
        l=tmpL;
        r=tmpR;
        d=tmpD;
    }
    Print(l);
    Print(r);
    Print(d);
    

    return 0;
}
