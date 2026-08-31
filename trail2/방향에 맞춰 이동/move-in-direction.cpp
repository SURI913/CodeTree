#include <iostream>

using namespace std;

int n;
char dir[100];
int dist[100];

const int dx[4] ={1,0,-1,0};
const int dy[4] = {0,-1,0,1};

int main() {
    cin >> n;
    int x=0; 
    int y=0;
    for (int i = 0; i < n; i++) {
        cin >> dir[i] >> dist[i];
        switch(dir[i]){
            case 'W': x += (dx[2]*dist[i]); break;
            case 'S': y += (dy[1]*dist[i]); break;
            case 'N': y += (dy[3]*dist[i]); break;
            case 'E': x += (dx[0]*dist[i]); break;
            default: break;
        }
    }
    
    cout << x << ' ' << y <<endl;
    // Please write your code here.

    return 0;
}