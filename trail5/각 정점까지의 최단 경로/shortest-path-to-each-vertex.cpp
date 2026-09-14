#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define MAX 300001
#define INF 987654321

using namespace std;

int n, m, k;

vector<pair<int, int>> graph[MAX];
int dist[MAX];

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        int current = pq.top().second;
        int cw = pq.top().first;
        pq.pop();
        if (cw > dist[current]) {
            continue;
        }

        for (auto& next : graph[current]) {
            if (dist[next.second] > dist[current] + next.first) {
                dist[next.second] = dist[current] + next.first;
                pq.push({dist[next.second], next.second});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> k;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    Dijkstra();

    // Please write your code here.
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;

    }

    return 0;
}
