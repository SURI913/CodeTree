#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 1001
#define INF 987654321

int n, m;
int from[100000], to[100000], weight[100000];
int dist[MAX];

vector<pair<int, int>> graph[MAX];
int A, B;

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    dist[B] = 0;
    pq.push({0, B});

    while (!pq.empty()) {
        int cNode = pq.top().second;
        int cWeight = pq.top().first;
        pq.pop();

        if(cWeight > dist[cNode]) continue;

        for (auto& next : graph[cNode]) {
            int nNode = next.second;
            int nWeight = next.first;

            if (dist[nNode] > dist[cNode] + nWeight) {
                dist[nNode] = dist[cNode] + nWeight;
                pq.push({dist[nNode], nNode});
            }
        }
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        graph[to[i]].push_back({weight[i], from[i]});
        graph[from[i]].push_back({weight[i], to[i]});
    }

    cin >> A >> B;
    Dijkstra();
    
    int current = A;
    vector<int> answer;
    answer.push_back(A);
    
    while (current != B) {
        int nextNode = INF;
        for(auto& next: graph[current]){
            int nNode = next.second;
            int nWeight = next.first;

            if(dist[current]==nWeight+dist[nNode]){
                nextNode = min(nextNode, nNode);
            }
        }
        current = nextNode;
        answer.push_back(current);
    }
    cout << dist[A] <<endl;
    for (int i = 0; i <answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
