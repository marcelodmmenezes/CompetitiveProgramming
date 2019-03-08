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

	int n, m;

	while (cin >> n >> m, n | m) {
		string c1, c2;
		unordered_map<string, int> creatures;

		vector<Subset> subsets(n);

		for (int i = 0; i < n; i++) {
			cin >> c1;
			creatures[c1] = i;

			subsets[i].parent = i;
			subsets[i].rank = 0;
			subsets[i].n_elements = 1;
		}

		int n_elements, largest_subset = 1;

		for (int i = 0; i < m; i++) {
			cin >> c1 >> c2;
			n_elements = _union(subsets, creatures[c1], creatures[c2]);

			if (n_elements > largest_subset)
				largest_subset = n_elements;
		}

		cout << largest_subset << '\n';
	}
}
