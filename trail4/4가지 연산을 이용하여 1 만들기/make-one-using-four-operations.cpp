#include <iostream>
#include <queue>

using namespace std;

int N;

int BFS(int n){
    queue<int> q;
    
    q.push(n);
    int oprator[4] ={-1,1,2,3}; //마지막 2,3은 0으로 떨어졌을 떄 나누기로나누기로
    int dist[1000001]={0,};
    bool visited [1000001]={false,};

    visited[n] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if(current == 1) break;

        for(int i =0; i< 4;i++){
            int next = current+oprator[i];
            if(i == 2){
                if(current % 2 != 0) continue;
                else next = current/oprator[i];
            }
            if(i == 3){
                if (current % 3 != 0) continue;
                else next = current/oprator[i];
            } 

            if(next >=0 && next <= 1000000 && !visited[next] ){ //순서 주의 숫자 크기부터 체크해야지 인덱스 값 안넘김
                visited[next] = true;
                q.push(next);
                dist[next] = dist[current] +1;
            }
        }
    }

    return dist[1];
}

int main() {
    cin >> N;

    // Please write your code here.

    int result  = BFS(N);

    cout << result<<endl;

    return 0;
}
