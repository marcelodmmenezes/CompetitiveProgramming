#include <bits/stdc++.h>
using namespace std;

vector<int> numbers[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, aux_i, aux_i2;

	while (cin >> n >> m) {
		for (int i = 0; i < 1000000; ++i)
			numbers[i].clear();

		for (int i = 0; i < n; ++i) {
			cin >> aux_i;
			numbers[aux_i - 1].push_back(i + 1);
		}

		for (int i = 0; i < m; ++i) {
			cin >> aux_i >> aux_i2;

			if (aux_i > numbers[aux_i2 - 1].size())
				cout << "0\n";
			else
				cout << numbers[aux_i2 - 1][aux_i - 1] << '\n';
		}
	}
}
