#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& g, int node) {
	queue<int> q;
	vector<bool> v(g.size(), false);

	q.push(node);
	v[node] = true;

	while (!q.empty()) {
		node = q.front();
		q.pop();

		cout << node << ' '; // For testing

		for (int i = 0; i < g[node].size(); ++i) {
			int current = g[node][i];

			if (!v[current]) {
				q.push(current);
				v[current] = true;
			}
		}
	}
}

void bfsDist(vector<vector<int>>& g, int node) {
	const int INF = 1000000000;

	queue<int> q;
	vector<int> dist(g.size(), INF);

	q.push(node);
	dist[node] = 0;

	while (!q.empty()) {
		node = q.front();
		q.pop();

		cout << node << " " << dist[node] << '\n'; // For testing

		for (int i = 0; i < g[node].size(); ++i) {
			int current = g[node][i];

			if (dist[current] == INF) {
				q.push(current);
				dist[current] = dist[node] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	vector<vector<int>> graph(n);

	int a, b;

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(graph, 0);
	cout << '\n';
	bfsDist(graph, 0);
}
