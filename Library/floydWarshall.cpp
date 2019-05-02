#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

void floydWarshall(vector<vector<int>>& g) {
	int n = g.size();

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, w;

	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, INF));

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		graph[a][b] = graph[b][a] = w;
	}

	for (int i = 0; i < n; ++i)
		graph[i][i] = 0; 

	floydWarshall(graph);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << graph[i][j] << ' ';

		cout << '\n';
	}
}
