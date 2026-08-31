#include <iostream>

using namespace std;

string dirs;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main() {
    int x=0, y=0;
    cin >> dirs;
    int currDir =3;
    for(int i =0; i< dirs.size();i++){
        switch(dirs[i]){
            case 'L':
            currDir = (currDir-1+4)%4; break;
            case 'R':
            currDir = (currDir+1)%4; break;
            case 'F':
            x +=dx[currDir];
            y +=dy[currDir];
            break;
            
        }
    }

    cout << x <<' '<<y<<endl;

    // Please write your code here.

    return 0;
}