#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

// Returns true if graph doesn't have a negative cycle
bool bellmanFord(vector<vector<pair<int, int>>>& g,
	vector<int>& dist, int s, int t) {
	dist[s] = 0;

    for (int i = 0; i < g.size() - 1; ++i) {
    	for (int j = 0; j < g.size(); ++j) {
    		for (int k = 0; k < g[j].size(); ++k) {
    			auto current = g[j][k];
    			dist[current.second] = min(dist[current.second],
    				dist[j] + current.first);
    		}
    	}
    }

    for (int i = 0; i < g.size(); ++i) {
    	for (int j = 0; j < g[i].size(); ++j) {
    		auto current = g[i][j];

    		if (dist[current.second] > dist[i] + current.first)
    			return false;
    	}
    }

    return true;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, w;

	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n);

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		graph[a].push_back({ w, b });
	}

	vector<int> dist(n, INF);

	cout << (bellmanFord(graph, dist, 0, n - 1) ?
		"Graph doesn't have a negative cycle\n" :
		"Graph has a negative cycle\n");

	for (int i = 0; i < n; ++i)
		cout << dist[i] << ' ';
	cout << endl;
}
