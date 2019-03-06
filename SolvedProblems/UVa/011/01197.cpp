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

	int n, m, k, v1, v2;

	while (cin >> n >> m, n || m) {
		vector<Subset> subsets(n);

		for (int i = 0; i < n; i++) {
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}

		while (m--) {
			cin >> k >> v1;

			while (--k) {
				cin >> v2;
				_union(subsets, v1, v2);
			}
		}

		v1 = _find(subsets, 0);

		int suspects = 1;

		for (int i = 1; i < n; i++)
			if (v1 == _find(subsets, i))
				++suspects;

		cout << suspects << '\n';
	}
}
