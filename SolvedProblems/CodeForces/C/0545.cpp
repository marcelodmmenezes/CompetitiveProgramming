#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<pair<int, int>> trees(n);
	vector<pair<int, int>> memo(n, pair<int, int>(0, 0));

	for (auto& it : trees)
		cin >> it.first >> it.second;

	memo[0].first = 1;

	for (int i = 1; i < n; ++i) {
		if (trees[i].first - trees[i].second > trees[i - 1].first + trees[i - 1].second)
			memo[i].first = 2 + memo[i - 1].second;
		else if (trees[i].first - trees[i].second > trees[i - 1].first)
			memo[i].first = 1 + max(memo[i - 1].first, memo[i - 1].second);
		else
			memo[i].first = 0;

		memo[i].second = max(memo[i - 1].first, memo[i - 1].second);

		if (trees[i].first > trees[i - 1].first + trees[i - 1].second)
			memo[i].second = max(memo[i].second, 1 + memo[i - 1].second);
	}

	cout << max(memo[n - 1].first, 1 + memo[n - 1].second) << '\n';
}

