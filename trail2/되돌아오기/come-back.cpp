#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
char dir;
int dist;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

map<char,int> mapper;
string dirSet = "WSNE"; //서남북동 

int main() {
    cin >> N;

    for (int i = 0; i < 4; i++) {
        mapper[dirSet[i]] = i;
    }

    int x=0,y=0,cnt =0;
    bool isComplet=false;
    int answer;

    for (int i = 0; i < N; i++) {
        cin >> dir>> dist;

        for(int j =0; j<dist; j++){
            x += dx[mapper[dir]];
            y += dy[mapper[dir]];
            cnt++;

            if(x == 0 && y ==0 && !isComplet) {
                isComplet =true;
                answer = cnt;
            }
        }
    }
    
    if(!isComplet) answer =-1;

    cout << answer << endl;

    // Please write your code here.

    return 0;
}
