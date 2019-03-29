#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_cases;

	cin >> n_cases;

	while (n_cases--) {
		int n, v, sum = 0;

		cin >> n;

		vector<int> sales(n);
		cin >> sales[0];

		for (int i = 1; i < n; ++i) {
			cin >> sales[i];

			for (int j = 0; j < i; ++j)
				if (sales[j] <= sales[i])
					++sum;
		}

		cout << sum << '\n';
	}
}