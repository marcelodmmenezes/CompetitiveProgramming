#include <bits/stdc++.h>
using namespace std;

struct Subset {
	int parent;
	int rank;
	int n_elements;
};

int _find(vector<Subset>& subsets, int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = _find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

int _union(vector<Subset>& subsets, int x, int y) {
	x = _find(subsets, x);
	y = _find(subsets, y);

	if (x == y)
		return 0;

	if (subsets[x].rank < subsets[y].rank)
		subsets[x].parent = y;
	else if (subsets[x].rank > subsets[y].rank)
		subsets[y].parent = x;
	else {
		subsets[x].parent = y;
		++subsets[y].rank;
	}

	subsets[x].n_elements += subsets[y].n_elements;
	return subsets[y].n_elements = subsets[x].n_elements;
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
			subsets[i].n_elements = 1;
		}

		int x, y, n_elements, largest_subset = 1;

		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			n_elements = _union(subsets, x - 1, y - 1);

			if (n_elements > largest_subset)
				largest_subset = n_elements;
		}

		cout << largest_subset << '\n';
	}
}
