#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& g, int node,
	vector<bool>& v, vector<int>& order) {
	v[node] = true;

	for (int i = 0; i < g[node].size(); ++i)
		if (!v[g[node][i]])
			dfs(g, g[node][i], v, order);

	order.push_back(node);
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
	}

	vector<bool> visited(n, false);
	vector<int> order;

	for (int i = 0; i < n; ++i)
		if (!visited[i])
			dfs(graph, i, visited, order);

	reverse(order.begin(), order.end());

	for (int i = 0; i < order.size(); ++i)
		cout << order[i] << ' ';
	cout << endl;
}
