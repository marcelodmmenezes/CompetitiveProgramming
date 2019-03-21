#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, n, n_positions, aux_i;

	while (cin >> m >> n) {
		vector<pair<int, int>> transpose[10001];

		for (int i = 0; i < m; ++i) {
			cin >> n_positions;
			vector<int> positions(n_positions);

			for (int j = 0; j < n_positions; ++j) {
				cin >> aux_i;
				positions[j] = aux_i - 1;
			}

			for (int j = 0; j < n_positions; ++j) {
				cin >> aux_i;
				transpose[positions[j]].push_back(
					make_pair(i + 1, aux_i));
			}
		}

		cout << n << ' ' << m << '\n';

		for (int i = 0; i < n; ++i) {
			cout << transpose[i].size();

			for (int j = 0; j < transpose[i].size(); ++j)
				cout << ' ' << transpose[i][j].first;

			cout << '\n';

			if (transpose[i].size() > 0)
				cout << transpose[i][0].second;

			for (int j = 1; j < transpose[i].size(); ++j)
				cout << ' ' << transpose[i][j].second;

			cout << '\n';
		}
	}
}
