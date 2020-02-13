#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, d;

	cin >> n >> d;

	vector<pair<long long, long long>> friends(n);

	for (auto& it : friends)
		cin >> it.first >> it.second;

	sort(friends.begin(), friends.end());

	long long low_i = 0;
	long long low = friends[0].first;
	long long sum = friends[0].second;
	long long higher = sum;

	for (int i = 1; i < n; ++i) {
		while (friends[i].first >= low + d) {
			sum -= friends[low_i++].second;
			low = friends[low_i].first;
		}

		sum += friends[i].second;
		higher = max(higher, sum);
	}

	cout << higher << '\n';
}

