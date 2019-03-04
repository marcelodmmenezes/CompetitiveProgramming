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

void _union(vector<Subset>& subsets, int x, int y, int& n) {
	x = _find(subsets, x);
	y = _find(subsets, y);

	if (x != y)
		n--;

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

	int n, m, x, y, cs = 1;

	while (cin >> n >> m, n, m) {
		vector<Subset> subsets(n);

		for (int i = 0; i < n; ++i) {
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}

		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			_union(subsets, x - 1, y - 1, n);
		}

		cout << "Case " << cs++ << ": " << n << '\n';
	}
}
