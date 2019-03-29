#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(4);

	int n_cases;

	cin >> n_cases;
	cin.get();
	cin.get();

	while (n_cases--) {
		int n_trees = 0;
		string tree;
		map<string, int> species;

		while (getline(cin, tree) && tree != "") {
			++species[tree];
			++n_trees;
		}

		for (auto& it : species)
			cout << it.first << " "
				<< (double)(it.second * 100.0) / n_trees << '\n';

		if (n_cases)
			cout << '\n';
	}
}
