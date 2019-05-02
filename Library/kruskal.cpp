#include <bits/stdc++.h>
using namespace std;

struct Subset {
	int parent;
	int rank;
};

int _find(vector<Subset>& subsets, int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = _find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void _union(vector<Subset>& subsets, int x, int y) {
	x = _find(subsets, x);
	y = _find(subsets, y);

	if (subsets[x].rank < subsets[y].rank)
		subsets[x].parent = y;
	else if (subsets[x].rank > subsets[y].rank)
		subsets[y].parent = x;
	else {
		subsets[x].parent = y;
		++subsets[y].rank;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, w;

	cin >> n >> m;

	vector<pair<int, pair<int, int>>> edges(m);

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		edges[i] = { w, { a, b }};
	}

	sort(edges.begin(), edges.end());

	vector<Subset> subsets(n);

	for (int i = 0; i < n; i++) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}

	int cost = 0;

	for (int i = 0; i < m; ++i) {
		auto front = edges[i];

		if (_find(subsets, front.second.first) !=
			_find(subsets, front.second.second)) {
			cost += front.first;
			_union(subsets, front.second.first, front.second.second);
		}
	}

	cout << cost << '\n';
}
