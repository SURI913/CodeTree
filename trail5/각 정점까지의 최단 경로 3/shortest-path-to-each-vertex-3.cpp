#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 101
#define INF 987654321

int n, m;
vector<pair<int,int>> grahp[MAX]; //a, 가중치, b  
int dist[MAX];


void Dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //int visited[MAX];
    dist[1] = 0;
    for(int i =2; i < MAX; i++){
        dist[i]=INF; //큰 값으로 초기화 필요
    }

    //visited[1] = true;
    pq.push({0,1});
    
    //자료형, 벡터안에 자료형, 제너레이터에 자료형
    //최소힙

    while(!pq.empty()){
        int current = pq.top().second;
        
        pq.pop();

        for(auto& vw: grahp[current]){
            int next = vw.second;
            int nWight = vw.first;

            if(dist[current] + nWight < dist[next]){
                dist[next] = dist[current] + nWight;
                pq.push({vw});
            }
        }

        
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b,w;
        cin >> a>>b>>w;
        grahp[a].push_back({w,b});
    }
    Dijkstra();
    //시작정점부터 끝정점까지 가중치 출력이라
    //시작정점 1은 가중치 0이니까 정점 2부터 n까지 해야함
    for(int i =2; i<=n; i++){
        if(dist[i] == INF){
            cout << -1 <<endl;
            continue;
        }
        cout << dist[i] <<endl;
    }
    // Please write your code here.

    return 0;
}
