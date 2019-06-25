#include <bits/stdc++.h>
using namespace std;

void recursiveDFS(vector<vector<int>>& g, vector<bool>& v, int node) {
	v[node] = true;

	cout << node << ' '; // For testing

	for (int i = 0; i < g[node].size(); ++i)
		if (!v[g[node][i]])
			recursiveDFS(g, v, g[node][i]);
}

void iterativeDFS(vector<vector<int>>& g, int node) {
	stack<int> s;
	vector<bool> v(g.size(), false);

	s.push(node);
	v[node] = true;

	while (!s.empty()) {
		node = s.top();
		s.pop();

		cout << node << ' '; // For testing

		for (int i = 0; i < g[node].size(); ++i) {
			int current = g[node][i];

			if (!v[current]) {
				s.push(current);
				v[current] = true;
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

	vector<bool> visited(n, false);

	recursiveDFS(graph, visited, 0);
	cout << '\n';
	iterativeDFS(graph, 0);
	cout << '\n';
}
