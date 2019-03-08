#include <bits/stdc++.h>
using namespace std;

struct Subset {
	int parent;
	int rank;
	int owe;
};

int _find(vector<Subset>& subsets, int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = _find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void _union(vector<Subset>& subsets, int x, int y) {
	x = _find(subsets, x);
	y = _find(subsets, y);

	if (x == y)
		return;

	if (subsets[x].rank < subsets[y].rank) {
		subsets[x].parent = y;
		subsets[y].owe += subsets[x].owe;
	}
	else if (subsets[x].rank > subsets[y].rank) {
		subsets[y].parent = x;
		subsets[x].owe += subsets[y].owe;
	}
	else {
		subsets[x].parent = y;
		subsets[y].owe += subsets[x].owe;
		++subsets[y].rank;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_cases;

	cin >> n_cases;

	while (n_cases--) {
		int n, m;

		cin >> n >> m;

		vector<Subset> subsets(n);

		for (int i = 0; i < n; i++) {
			subsets[i].parent = i;
			subsets[i].rank = 0;
			cin >> subsets[i].owe;
		}

		int x, y;

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			_union(subsets, x, y);
		}

		bool possible = true;

		for (int i = 0; i < n; i++) {
			if (subsets[_find(subsets, i)].owe != 0) {
				possible = false;
				break;
			}
		}

		if (possible)
			cout << "POSSIBLE\n";
		else
			cout << "IMPOSSIBLE\n";
	}
}
