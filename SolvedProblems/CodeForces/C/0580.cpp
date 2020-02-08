#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, sum = 0;
vector<vector<int>> tree;
vector<bool> visited;
vector<bool> has_cats;

void search(int node, int n_cats) {
	if (n_cats > m)
		return;

	if (tree[node].size() == 1 && node != 0) {
		if (n_cats + has_cats[node] <= m)
			++sum;

		return;
	}

	visited[node] = true;

	for (int i = 0; i < tree[node].size(); ++i)
		if (!visited[tree[node][i]])
			search(tree[node][i], has_cats[node] * (n_cats + 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	tree.resize(n);
	visited = vector<bool>(n, false);
	has_cats.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> x;
		has_cats[i] = x;
	}

	for (int i = 0; i < n - 1; ++i) {
		cin >> x >> y;
		tree[x - 1].push_back(y - 1);
		tree[y - 1].push_back(x - 1);
	}

	search(0, 0);

	cout << sum << '\n';
}

