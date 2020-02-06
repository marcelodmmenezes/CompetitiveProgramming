#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<int> v(n);

	for (auto &it : v)
		cin >> it;

	sort(v.begin(), v.end());

	long long sum = 0;

	for (int i = 0; i < n / 2; ++i) {
		long long sqr = v[i] + v[n - i - 1];
		sum += sqr * sqr; 
	}

	cout << sum << '\n';
}

