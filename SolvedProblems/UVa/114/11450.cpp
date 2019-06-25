#include <bits/stdc++.h>
using namespace std;

#define MIN_INF -9999999

int money;
int memo[210][30];

int pd(int m, int c, vector<vector<int>>& g) {
	if (m < 0)
		return MIN_INF;

	if (memo[m][c] != -1)
		return memo[m][c];

	if (c == g.size())
		return money - m;

	int mx = -1;

	for (int i = 0; i < g[c].size(); ++i)
		mx = max(mx, pd(m - g[c][i], c + 1, g));

	return memo[m][c] = mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	while (n--) {
		int c, k;

		cin >> money >> c;

		vector<vector<int>> garnments(c);

		for (int i = 0; i < c; ++i) {
			cin >> k;

			garnments[i].resize(k);

			for (int j = 0; j < k; ++j)
				cin >> garnments[i][j];
		}

		for (int i = 0; i <= money; ++i)
			for (int j = 0; j <= c; ++j)
				memo[i][j] = -1;

		int res = pd(money, 0, garnments);

		if (res < 0)
			cout << "no solution\n";
		else
			cout << res << '\n';
	}
}
