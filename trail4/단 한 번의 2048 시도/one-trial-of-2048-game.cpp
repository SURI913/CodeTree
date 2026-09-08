#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
#define MAX 4

int grid[MAX][MAX];
int temp[MAX][MAX];
char dir;

vector<int> Merge(vector<int> line){

    vector<int> c;
    bool isMerge = false;

    for( auto num: line){
        if(num == 0) continue;
        if(!c.empty() && num == c.back() && !isMerge){
            
            c.pop_back();
            c.push_back(num*2);
            isMerge = true;
        }
        else {
            c.push_back(num);
            isMerge = false;
        }  
    }

    return c;
}


int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;
    

    if(dir == 'R'){
        //오른쪽 -> 왼쪽
        for (int i = 0; i < MAX; i++) {

            vector<int> line;
            for(int j = MAX-1; j>=0; j--){
                if(grid[i][j] != 0){
                    line.push_back(grid[i][j]);
                }
            }
            vector<int> result = Merge(line);

            for(int j = 0; j < result.size(); j++){
                temp[i][MAX-1-j] = result[j];
            }
        }
        
    }
    else if(dir == 'L'){
        //왼쪽 -> 오른쪽
        for (int i = 0; i < MAX; i++) {

            vector<int> line;
            for(int j = 0; j < MAX; j++){
                if(grid[i][j] != 0){
                    line.push_back(grid[i][j]);
                }
            }
            vector<int> result = Merge(line);

            for(int j = 0; j < result.size(); j++){
                temp[i][j] = result[j];
            }
        }
        
    }
    else if(dir == 'U'){
        //위 -> 아래
        for (int i = 0; i < MAX; i++) {

            vector<int> line;
            for(int j = 0; j < MAX; j++){
                if(grid[j][i] != 0){
                    line.push_back(grid[j][i]);
                }
            }
            vector<int> result = Merge(line);

            for(int j = 0; j < result.size(); j++){
                temp[j][i] = result[j];
            }
        }
        
    }
    else if(dir == 'D'){
        //아래 -> 아래
        for (int i = 0; i < MAX; i++) {

            vector<int> line;
            for(int j = MAX-1; j>=0; j--){
                if(grid[j][i] != 0){
                    line.push_back(grid[j][i]);
                }
            }
            vector<int> result = Merge(line);

            for(int j = 0; j < result.size(); j++){
                temp[MAX-1-j][i] = result[j];
            }
        }
        
    }


    // Please write your code here.
     for(int i =0; i <MAX; i++){
        for(int j =0; j < MAX; j++){
            cout << temp[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
