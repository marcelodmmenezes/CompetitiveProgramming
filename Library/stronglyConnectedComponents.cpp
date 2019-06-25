#include <bits/stdc++.h>
using namespace std;

void tarjan(vector<vector<int>>& graph, vector<int>& stck,
	vector<int>& dfs_num, vector<int>& dfs_low,
	vector<bool>& visited, int& counter, int node,
	int& num_of_ssc) {
	dfs_low[node] = dfs_num[node] = counter++;
	stck.push_back(node);
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); ++i) {
		int current = graph[node][i];

		if (dfs_num[current] == -1)
			tarjan(graph, stck, dfs_num, dfs_low,
				visited, counter, current, num_of_ssc);

		if (visited[current])
			dfs_low[node] = min(dfs_low[node], dfs_low[current]);
	}

	if (dfs_low[node] == dfs_num[node]) {
		cout << "SSC " << ++num_of_ssc << ':';

		while (true) {
			int v = stck.back();
			stck.pop_back();
			visited[v] = 0;

			cout << ' ' << v;

			if (v == node)
				break;
		}

		cout << '\n';
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
	}

	int counter = 0, num_of_ssc = 0;
	vector<int> stck;
	vector<int> dfs_num(n, -1);
	vector<int> dfs_low(n, 0);
	vector<bool> visited(n, false);

	for (int i = 0; i < n; ++i)
		if (dfs_num[i] == -1)
			tarjan(graph, stck, dfs_num, dfs_low,
				visited, counter, i, num_of_ssc);
}
