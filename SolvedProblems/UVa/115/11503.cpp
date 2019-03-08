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

	if (subsets[x].rank < subsets[y].rank)
		subsets[x].parent = y;
	else if (subsets[x].rank > subsets[y].rank)
		subsets[y].parent = x;
	else {
		subsets[x].parent = y;
		++subsets[y].rank;
	}

	if (x != y) {
		subsets[x].n_elements += subsets[y].n_elements;
		subsets[y].n_elements = subsets[x].n_elements;
	}

	return subsets[x].n_elements;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_cases;
	vector<Subset> subsets(100001);

	cin >> n_cases;

	while (n_cases--) {
		int n;

		cin >> n;

		string p1, p2;
		unordered_map<string, int> people;

		int pos = 0;

		for (int i = 0; i < n; i++) {
			cin >> p1 >> p2;

			if (people.find(p1) == people.end()) {
				subsets[pos].parent = pos;
				subsets[pos].rank = 0;
				subsets[pos].n_elements = 1;
				people[p1] = pos++;
			}

			if (people.find(p2) == people.end()) {
				subsets[pos].parent = pos;
				subsets[pos].rank = 0;
				subsets[pos].n_elements = 1;
				people[p2] = pos++;
			}

			cout << _union(subsets, people[p1], people[p2]) << '\n';
		}
	}
}
