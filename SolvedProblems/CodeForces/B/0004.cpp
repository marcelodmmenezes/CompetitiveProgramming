#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int d, sum_time, lower = 0, higher = 0;

	cin >> d >> sum_time;

	vector<pair<int, int>> schedule(d);

	for (auto& it : schedule) {
		cin >> it.first >> it.second;
		lower += it.first;
		higher += it.second;
	}

	if (sum_time < lower || sum_time > higher) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	int missing = sum_time - lower;

	for (int i = 0; i < d; ++i) {
		int delta = schedule[i].second - schedule[i].first;

		if (missing >= delta) {
			cout << schedule[i].second << ' ';
			missing -= delta;
		}
		else if (missing > 0) {
			cout << schedule[i].first + missing << ' ';
			missing = 0;
		}
		else
			cout << schedule[i].first << ' ';
	}

	cout << '\n';
}

