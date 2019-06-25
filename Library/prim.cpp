#include <bits/stdc++.h>
using namespace std;

int prim(vector<vector<pair<int, int>>>& g) {
	vector<bool> v(g.size(), false);
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	pq.push({ 0, 0 });

	int cost = 0;

	while (!pq.empty()) {
		auto node = pq.top();
		pq.pop();

		if (!v[node.second]) {
			v[node.second] = true;
			cost += node.first;

			for (int i = 0; i < g[node.second].size(); ++i) {
				auto current = g[node.second][i];

				if (!v[current.second])
					pq.push(current);
			}
		}
	}

	return cost;
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

	cout << prim(graph) << '\n';
}
