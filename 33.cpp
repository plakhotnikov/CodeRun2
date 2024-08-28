// 33. Ухудшение графа

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> dijkstra(int n, int start, const vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_dist > dist[u]) {
            continue;
        }

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int solve(int n, const vector<vector<int>>& matrix) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != -1 && i != j) {
                adj[i].push_back({j, matrix[i][j]});
            }
        }
    }

    vector<int> original_dist = dijkstra(n, 0, adj);
    int max_changed = 0;

    for (int u = 0; u < n; ++u) {
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            int w = it->second;

            if (u < v && matrix[u][v] != -1) {
                if (original_dist[u] + w == original_dist[v]) {
                    auto it2 = find_if(adj[v].begin(), adj[v].end(), [u](const pair<int, int>& p) {
                        return p.first == u;
                    });

                    vector<pair<int, int>> u_backup = adj[u];
                    vector<pair<int, int>> v_backup = adj[v];

                    adj[u].erase(it);
                    if (it2 != adj[v].end()) {
                        adj[v].erase(it2);
                    }

                    vector<int> new_dist = dijkstra(n, 0, adj);

                    int changed = 0;
                    for (int k = 0; k < n; ++k) {
                        if (original_dist[k] != new_dist[k]) {
                            ++changed;
                        }
                    }

                    max_changed = max(max_changed, changed);

                    adj[u] = u_backup;
                    adj[v] = v_backup;
                }
            }
        }
    }

    return max_changed;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = solve(n, matrix);
    cout << result << endl;

    return 0;
}

