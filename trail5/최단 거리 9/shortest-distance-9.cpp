#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
#define MAX 100001
#define INF 987654321

int n, m;
int from[100000], to[100000], weight[100000];
int A, B;

vector<pair<int, int>> graph[MAX];
int parent[MAX];


int Dijkstra() {
    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    int dist[MAX];
    for (int i = 1; i <MAX; i++) {
        dist[i] = INF;
    }
    dist[A] = 0;
    pq.push({0, A});

    while (!pq.empty()) {
        int currentNode = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        if (currentWeight > dist[currentNode]) continue;

        for (auto& next : graph[currentNode]) {
            int nextNode = next.second;
            int nextWeight = next.first;
            if (dist[nextNode] > dist[currentNode] + nextWeight) {
                dist[nextNode] = dist[currentNode] + nextWeight;
                pq.push({dist[nextNode], nextNode});
                parent[nextNode] = currentNode; //부모경로 저장했어야함
            }
        }

    }

    return dist[B];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> weight[i];
        graph[from[i]].push_back({weight[i], to[i]});
        graph[to[i]].push_back({weight[i], from[i]});
    }

    cin >> A >> B;

    int min = Dijkstra();

    cout << min << endl;
    vector<int> answer;
    int current = B;

    while (current !=A){
        answer.push_back(current);
        current = parent[current];
    }

    answer.push_back(A);

    for (int i = answer.size()-1; i>=0; i--) {
        cout << answer[i] << " ";
    }
    cout << endl;
    // Please write your code here.

    return 0;
}
