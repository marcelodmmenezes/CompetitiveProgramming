#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
 
int memo[2010][2010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, k;

	cin >> n >> k;
 
	for (int i = 0; i <= n; ++i)
		memo[i][1] = 1;

	for (int i = 0; i <= k; ++i)
		memo[1][i] = 1;

	int sum = 1;

	for (int i = 2; i <= n; ++i) {
		int root = sqrt(i);

		for (int j = 2; j <= k; ++j) {
			memo[i][j] = 0;

			int it = 1;

			while (it <= root) {
				if (i % it == 0) {
					memo[i][j] += memo[it][j - 1];
					memo[i][j] %= MOD;

					if (it < root || i / root != root) {
						memo[i][j] += memo[i / it][j - 1];
						memo[i][j] %= MOD;
					}
				}

				++it;
			}
		}

		sum += memo[i][k];
		sum %= MOD;
	}

	cout << sum << '\n';
}

