#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

void dijkstra(vector<vector<pair<int, int>>>& g,
	vector<int>& parent, vector<int>& dist, int s, int t) {
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	pq.push({ 0, s });
	dist[s] = 0;

	while (!pq.empty()) {
		auto node = pq.top();
		pq.pop();

		if (node.second == t) // Found destination vertex
			return;

		if (node.first > dist[node.second])
			continue;

		for (int i = 0; i < g[node.second].size(); ++i) {
			auto current = g[node.second][i];

			if (dist[node.second] + current.first < dist[current.second]) {
				dist[current.second] = dist[node.second] + current.first;
				parent[current.second] = node.second;
				pq.push({ dist[current.second], current.second });
			}
		}
	}
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
		graph[b].push_back({ w, a });
	}

	vector<int> parent(n, -1);
	vector<int> dist(n, INF);

	dijkstra(graph, parent, dist, 0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << dist[i] << " " << parent[i] << endl;
}
