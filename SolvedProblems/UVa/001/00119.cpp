#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	bool first = true;

	while (cin >> n) {
		if (first)
			first = false;
		else
			cout << '\n';

		vector<pair<string, int>> people(n);
		unordered_map<string, int> people_id;

		for (int i = 0; i < n; ++i) {
			cin >> people[i].first;
			people[i].second = 0;
			people_id[people[i].first] = i;
		}

		int amount, m;
		string person;

		for (int i = 0; i < n; ++i) {
			cin >> person >> amount >> m;

			if (m) {
				people[people_id[person]].second -= amount / m * m;

				for (int j = 0; j < m; ++j) {
					cin >> person;
					people[people_id[person]].second += amount / m;
				}
			}
		}

		for (auto& it : people)
			cout << it.first << ' ' << it.second << '\n';
	}
}
