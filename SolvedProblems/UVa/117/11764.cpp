#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_cases;

	cin >> n_cases;

	for (int i = 1; i <= n_cases; ++i) {
		int n, wall1, wall2, n_high_jumps = 0, n_low_jumps = 0;

		cin >> n >> wall1;

		for (int j = 1; j < n; ++j) {
			cin >> wall2;

			if (wall2 > wall1)
				++n_high_jumps;
			else if (wall2 < wall1)
				++n_low_jumps;

			wall1 = wall2;
		}

		cout << "Case " << i << ": " << n_high_jumps
			<< " " << n_low_jumps << '\n';
	}
}
