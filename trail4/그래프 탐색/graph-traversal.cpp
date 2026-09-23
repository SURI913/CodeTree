#include <iostream>
#include <vector>

using namespace std;
#define MAX 1001

int n, m;
vector<int> graph[MAX];
int visited[MAX];
int result;

void DFS(int current) {

    for (auto& next : graph[current]) {
        if (!visited[next]) {
            visited[next] = true;
            result++;
            DFS(next);
        }

    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    visited[1] = true;
    DFS(1);

    cout << result << endl;
    // Please write your code here.

    return 0;
}
