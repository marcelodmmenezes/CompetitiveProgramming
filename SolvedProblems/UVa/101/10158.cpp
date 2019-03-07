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

	int n;

	cin >> n;

	vector<Subset> subsets(2 * n);

	for (int i = 0; i < 2 * n; i++) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}

	int c, x, y, en_x, en_y;

	while (cin >> c >> x >> y, c | x | y) {
		en_x = _find(subsets, x + n);
		en_y = _find(subsets, y + n);
		x = _find(subsets, x);
		y = _find(subsets, y);

		switch (c) {
		case 1:
			if (x != en_y) {
				_union(subsets, x, y);
				_union(subsets, en_x, en_y);
			}
			else
				cout << "-1\n";

			break;

		case 2:
			if (x != y) {
				_union(subsets, x, en_y);
				_union(subsets, y, en_x);
			}
			else
				cout << "-1\n";

			break;

		case 3:
			if (x == y)
				cout << "1\n";
			else
				cout << "0\n";

			break;

		case 4:
			if (x == en_y)
				cout << "1\n";
			else
				cout << "0\n";

			break;
		}
	}
}
