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

	int t, n, v1, v2;
	char c;

	cin >> t;

	while (t--) {
		cin >> n;

		vector<Subset> subsets(n + 1);

		for (int i = 0; i < n + 1; ++i) {
			subsets[i].parent = i;
			subsets[i].rank = 0;
		}

		int success = 0, failure = 0;

		while (cin >> c && (c == 'c' || c == 'q')) {
			cin >> v1 >> v2;

			if (c == 'c')
				_union(subsets, v1, v2);
			else {
				v1 = _find(subsets, v1);
				v2 = _find(subsets, v2);

				if (v1 == v2)
					++success;
				else
					++failure;
			}
		}

		cout << success << ',' << failure << '\n';

		if (t > 0)
			cout << '\n';

		cin.putback(c);
	}
}
