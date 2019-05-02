#include <bits/stdc++.h>
using namespace std;

void articulationsAndBridges(vector<vector<int>>& graph, vector<int>& parent,
	vector<int>& dfs_num, vector<int>& dfs_low, vector<bool>& articulations,
	int& counter, int node, int root, int& root_children) {
	dfs_low[node] = dfs_num[node] = counter++;

	for (int i = 0; i < graph[node].size(); ++i) {
		int current = graph[node][i];

		if (dfs_num[current] == -1) {
			parent[current] = node;

			if (node == root)
				++root_children;

			articulationsAndBridges(graph, parent, dfs_num, dfs_low,
				articulations, counter, current, root, root_children);

			if (dfs_low[current] >= dfs_num[node])
				articulations[node] = true;

			if (dfs_low[current] > dfs_num[node])
				cout << "Edge " << node << " -> "
					<< current << " is a bridge\n";

			dfs_low[node] = min(dfs_low[node], dfs_low[current]);
		}
		else if (current != parent[node])
			dfs_low[node] = min(dfs_low[node], dfs_num[current]);
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

	int counter = 0;
	vector<int> parent(n, -1);
	vector<int> dfs_num(n, -1);
	vector<int> dfs_low(n, 0);
	vector<bool> articulations(n, false);

	for (int i = 0; i < n; ++i) {
		if (dfs_num[i] == -1) {
			int root = i, root_children = 0;
			articulationsAndBridges(graph, parent, dfs_num, dfs_low,
				articulations, counter, root, root, root_children);
			articulations[root] = (root_children > 1);
		}
	}

	cout << "Articulations:\n";

	for (int i = 0; i < articulations.size(); ++i)
		if (articulations[i])
			cout << i << ' ';
	cout << endl;
}
