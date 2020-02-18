#include <bits/stdc++.h>

using namespace std;

bool cmpX(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.first < p2.first;
}

bool cmpY(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<pair<int, int>> x(n), y(n);
	map<pair<int, int>, int> n_equals;

	for (int i = 0; i < n; ++i) {
		cin >> x[i].first >> x[i].second;
		y[i] = x[i];
		++n_equals[x[i]];
	}

	sort(x.begin(), x.end(), cmpX);
	sort(y.begin(), y.end(), cmpY);

	long long sum = 0ll, count_x = 0ll, count_y = 0ll;

	for (int i = 1; i < n; ++i) {
		if (x[i].first == x[i - 1].first)
			++count_x;
		else {
			sum += count_x * (count_x + 1ll) / 2ll;
			count_x = 0ll;
		}

		if (y[i].second == y[i - 1].second)
			++count_y;
		else {
			sum += count_y * (count_y + 1ll) / 2ll;
			count_y = 0ll;
		}
	}

	sum += count_x * (count_x + 1ll) / 2ll;
	sum += count_y * (count_y + 1ll) / 2ll;

	for (auto& it : n_equals) {
		--it.second;
		sum -= it.second * (it.second + 1ll) / 2ll;
	}

	cout << sum << '\n';
}

