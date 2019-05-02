#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& g, int node) {
	queue<int> q;
	vector<int> color(g.size(), -1);

	q.push(node);
	color[node] = 0;

	while (!q.empty()) {
		node = q.front();
		q.pop();

		for (int i = 0; i < g[node].size(); ++i) {
			int current = g[node][i];

			if (color[current] == -1) {
				color[current] = 1 - color[node];
				q.push(current);
			}
			else if (color[current] == color[node])
				return false;
		}
	}

	return true;
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

	vector<bool> visited(n, false);

	cout << isBipartite(graph, 0) << '\n';
}
