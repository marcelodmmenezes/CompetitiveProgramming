#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int g_n, g_k, g_d;
int memo[200][2];

int pd(int sum, bool has_d) {
	if (sum < 0)
		return 0;

	if (memo[sum][has_d] != -1)
		return memo[sum][has_d];

	if (sum == 0 && has_d)
		return memo[sum][has_d] = 1;

	memo[sum][has_d] = 0;

	for (int i = 1; i <= g_k; ++i) {
		memo[sum][has_d] += pd(sum - i, has_d || i >= g_d);
		memo[sum][has_d] %= MOD;
	}

	return memo[sum][has_d];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> g_n >> g_k >> g_d;

	for (int i = 0; i <= g_n; ++i)
		for (int j = 0; j < 2; ++j)
			memo[i][j] = -1;

	cout << pd(g_n, false) << '\n';
}

