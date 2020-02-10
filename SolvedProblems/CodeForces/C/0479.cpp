#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<pair<int, int>> v(n);

	for (auto& it : v)
		cin >> it.first >> it.second;

	sort(v.begin(), v.end());

	int d = v[0].second;

	for (int i = 1; i < n; ++i) {
		if (v[i].second >= d)
			d = v[i].second;
		else
			d = v[i].first;
	}

	cout << d << '\n';
}

