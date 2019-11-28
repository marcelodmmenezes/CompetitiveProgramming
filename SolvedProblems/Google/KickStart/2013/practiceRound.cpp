#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, vector<int>& colors,
	int node, int current_color) {
	colors[node] = current_color;

	for (int i = 0; i < graph[node].size(); ++i) {
		if (colors[graph[node][i]] > -1 &&
			colors[graph[node][i]] == current_color)
			return false;
			
		if (colors[graph[node][i]] == -1 &&
			!dfs(graph, colors, graph[node][i], 1 - current_color))
			return false;
	}

	return true;
}

bool twoColor(vector<vector<int>>& graph) {
	vector<int> colors(graph.size(), -1);

	for (int i = 0; i < graph.size(); ++i)
		if (colors[i] == -1 &&
			!dfs(graph, colors, i, 0))
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int test = 1, t, m;

	cin >> t;

	string name_1, name_2;

	while (t--) {
		vector<vector<int>> graph;
		map<string, int> nodes;
		int id = 0;

		cin >> m;

		while (m--) {
			cin >> name_1 >> name_2;

			auto it = nodes.find(name_1);

			int current_id_1;

			if (it == nodes.end()) {
				graph.push_back(vector<int>());
				nodes[name_1] = current_id_1 = id++;
			}
			else
				current_id_1 = it->second;

			it = nodes.find(name_2);

			int current_id_2;

			if (it == nodes.end()) {
				graph.push_back(vector<int>());
				nodes[name_2] = current_id_2 = id++;
			}
			else
				current_id_2 = it->second;

			graph[current_id_1].push_back(current_id_2);
			graph[current_id_2].push_back(current_id_1);
		}

		if (twoColor(graph))
			cout << "Case #" << test++ << ": Yes\n";
		else
			cout << "Case #" << test++ << ": No\n";
	}
}

