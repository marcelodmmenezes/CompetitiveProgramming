#include <bits/stdc++.h>

using namespace std;

#define N 100010

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<long long> freq(N, 0);
	vector<long long> memo(N, 0);

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++freq[x];
	}

	memo[1] = freq[1];

	for (int i = 2; i < N; ++i)
		memo[i] = max(memo[i - 1], memo[i - 2] + i * freq[i]);

	cout << memo[N - 1] << '\n';
}

