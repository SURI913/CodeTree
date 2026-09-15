#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define MAX 1001
#define INF 987654321

int n, m;
vector<pair<int, int>> graph[MAX];
int A, B;

int Dijkstra() {
    priority_queue<pair<int, int>,
    vector<pair<int,int>>, greater<pair<int,int>>> pq;
    //최소힙
    int dist[MAX];
    for(int i =0; i<=n; i++){
        dist[i] = INF;
    }

    //초기 입력값
    pq.push({0,A});
    dist[A]=0;

    //BFS탐색
    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        //cout << "확인: " << dist[currentNode] <<endl;

        if(dist[currentNode] < currentWeight) continue;

        //다음 노드 탐색
        for(auto& next: graph[currentNode]){
            int nextNode = next.second;
            int nextWeight = dist[currentNode]+next.first;

             if(dist[currentNode] < currentWeight) continue;
        
            if(dist[nextNode] > nextWeight){
                //올값보다 지금 값이 더 작다면
                dist[nextNode] = nextWeight;
                //반대로 넣지마라
                pq.push({nextWeight, nextNode});
                // cout << "확인: " << currentNode << " " <<
                //  nextNode << " " << dist[nextNode] <<endl;
            }
        }
    }
    return dist[B];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        //양방향 그래프
        graph[from].push_back({weight, to});
        graph[to].push_back({weight, from});
    }

    cin >> A >> B;

    int answer = Dijkstra();

    cout << answer << endl;
    // Please write your code here.

    return 0;
}
