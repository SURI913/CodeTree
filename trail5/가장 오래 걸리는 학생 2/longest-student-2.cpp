#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define MAX 100001
#define INF 987654321

int N, M;
int i[100000], j[100000], d[100000];
vector<pair<int, int>> graph[MAX];

int Dijkstra() {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
        > pq;
    int dist[MAX] = {0,};
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[N] = 0;
    pq.push({0, N});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        if (currentWeight > dist[currentNode])
            continue;

        for (auto& next : graph[currentNode]) {
            int nextNode = next.second;
            int nextWeight = next.first;

            if (dist[nextNode] > dist[currentNode] + nextWeight) {
                dist[nextNode] = dist[currentNode] + nextWeight;
                //노드 추가
                pq.push({dist[nextNode], nextNode});
            }
        }

    }

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if(dist[i] > max){
            max = dist[i];
        }
        
    }
    return max;

}

int main() {
    cin >> N >> M;
    for (int k = 0; k < M; k++) {
        cin >> i[k] >> j[k] >> d[k];
        graph[j[k]].push_back({d[k], i[k]});
    }

    // Please write your code here.
    long long answer = Dijkstra();

    cout << answer << endl;

    return 0;
}
