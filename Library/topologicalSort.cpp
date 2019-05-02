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

// Returns true if its a DAG, false if graph contains a cycle
bool kahn(vector<vector<int>>& g, vector<int>& order) {
	vector<int> in_degree(g.size(), 0); 
  
  	// in_degree calculation can be done at input reading
    for (int i = 0; i < g.size(); ++i)
    	for (int j = 0; j < g[i].size(); ++j)
    		++in_degree[g[i][j]];
  
    queue<int> q;

    for (int i = 0; i < g.size(); ++i)
        if (in_degree[i] == 0)
            q.push(i);

    int n_visited = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

 		order.push_back(node);

 		for (int i = 0; i < g[node].size(); ++i)
 			if (--in_degree[g[node][i]] == 0)
 				q.push(g[node][i]);

 		++n_visited;
    }

    if (n_visited != g.size())
    	return false;

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
	}

	//--------------------------------------------------------------------- DFS
	vector<bool> visited(n, false);
	vector<int> order;

	for (int i = 0; i < n; ++i)
		if (!visited[i])
			dfs(graph, i, visited, order);

	reverse(order.begin(), order.end());

	for (int i = 0; i < order.size(); ++i)
		cout << order[i] << ' ';
	cout << endl;
	//-------------------------------------------------------------------------

	//------------------------------------------------------------------ Kahn's
	fill(visited.begin(), visited.end(), false);
	order.clear();

	if (!kahn(graph, order))
		cout << "Graph is not a DAG\n";
	else {
		for (int i = 0; i < order.size(); ++i)
			cout << order[i] << ' ';
		cout << endl;
	}
	//-------------------------------------------------------------------------
}
