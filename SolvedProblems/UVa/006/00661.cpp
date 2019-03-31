#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, c, sequence = 0;

	while (cin >> n >> m >> c, n | m | c) {
		vector<int> consumption(n);
		vector<bool> on(n);

		for (int i = 0; i < n; ++i) {
			cin >> consumption[i];
			on[i] = false;
		}

		int amp = 0, highest = 0, device;

		for (int i = 0; i < m; ++i) {
			cin >> device;

			--device;

			if (highest <= c) {
				if (on[device])
					amp -= consumption[device];
				else
					amp += consumption[device];

				highest = max(highest, amp);

				on[device] = !on[device];
			}
		}

		cout << "Sequence " << ++sequence << '\n';

		if (highest <= c)
			cout << "Fuse was not blown.\nMaximal power consumption was "
				<< highest << " amperes.\n\n";
		else
			cout << "Fuse was blown.\n\n";
	}
}
