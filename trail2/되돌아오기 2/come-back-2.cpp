#include <iostream>
#include <string>

using namespace std;

string commands;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


int main() {
    cin >> commands;
    int dir =0;
    int x =0, y =0;
    int answer;
    bool isComplet=false;

    for(int i =0; i< commands.length();i++){
        switch (commands[i]) {
            case 'L':
                dir = (dir+3)%4;
                break;
            case 'R':
                dir = (dir +1)%4;
                break;
            case 'F':
                x += dx[dir];
                y += dy[dir];

                if(x==0&&y==0&& !isComplet) {
                    isComplet = true;
                    answer = i+1;//i가 0이라
                }
                break;
        }

    }

    if(!isComplet)answer =-1;

    cout << answer << endl;

    // Please write your code here.

    return 0;
}
