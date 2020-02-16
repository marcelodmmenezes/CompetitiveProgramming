#include <bits/stdc++.h>
 
using namespace std;
 
int m, n, x, y;
vector<int> employees[100];
vector<int> languages[100];
vector<bool> visited;
bool graph[100][100] = { 0 };
 
void dfs(int node) {
	visited[node] = true;
 
	for (int i = 0; i < employees[node].size(); ++i) {
		int language_id = employees[node][i];
 
		for (int j = 0; j < languages[language_id].size(); ++j) {
			int employee_id = languages[language_id][j];
 
			graph[node][employee_id] = true;
 
			if (!visited[employee_id])
				dfs(employee_id);
		}
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	cin >> n >> m;

	int n_zero_rows = 0;

	for (int i = 0; i < n; ++i) {
		cin >> x;
 
		if (x == 0)
			++n_zero_rows;

		for (int j = 0; j < x; ++j) {
			cin >> y;

			employees[i].push_back(y - 1);
			languages[y - 1].push_back(i);
		}
	}

	if (n_zero_rows == n) {
		cout << n << '\n';
		return 0;
	}

	visited.resize(n, false);
 
	for (int i = 0; i < n; ++i)
		if (!visited[i])
			dfs(i);
 
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
 
	int n_components = 0;

	fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			for (int j = i + 1; j < n; ++j) {
				if (!visited[j]) {
					bool not_scc = false;

					for (int k = 0; k < n; ++k)
						not_scc |= graph[i][k] ^ graph[j][k];

					visited[j] = !not_scc;
				}
			}

			++n_components;
		}

		visited[i] = true;
	}
	
	cout << n_components - 1 + max(0, n_zero_rows - 1) << '\n';
}

