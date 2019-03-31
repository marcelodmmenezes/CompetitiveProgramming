#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<pair<string, int>> urls(10);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int v, relevance = 0;

		for (int j = 0; j < 10; ++j) {
			cin >> urls[j].first >> urls[j].second;
			relevance = max(relevance, urls[j].second);
		}

		cout << "Case #" << i << ":\n";

		for (int j = 0; j < 10; ++j)
			if (urls[j].second == relevance)
				cout << urls[j].first << '\n';
	}
}
