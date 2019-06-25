#include <bits/stdc++.h>
using namespace std;

enum NodeState {
	UNVISITED,
	VISITED,
	EXPLORED
};

void graphCheck(vector<vector<int>>& g, vector<NodeState>& state,
	vector<int>& parent, int node) {
	state[node] = EXPLORED;

	for (int i = 0; i < g[node].size(); ++i) {
		int current = g[node][i];

		if (state[current] == UNVISITED) {
			parent[current] = node;
			graphCheck(g, state, parent, current);
		}
		else if (state[current] == EXPLORED) {
			if (current == parent[node]) // Bidirectional edge
				cout << node << " <-> " << current
					<< " is a Bidirectional edge\n";
			else // Cycle
				cout << "Graph has a cycle\n";
		}
		else
			cout << node << " -> " << current << " is a forward edge\n";
	}

	state[node] = VISITED;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b;

	cin >> n >> m;

	vector<vector<int>> graph(n);

	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<NodeState> state(n, UNVISITED);
	vector<int> parent(n, -1);

	graphCheck(graph, state, parent, 0);
}
