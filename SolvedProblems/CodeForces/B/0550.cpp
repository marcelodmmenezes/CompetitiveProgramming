#include <bits/stdc++.h>

using namespace std;

#define INF 1012012012

int n, l, r, x;
int difficulty[15];

int bruteForce(int it, int sum, int lower, int higher) {
	if (it == n) {
		if (sum >= l && sum <= r && higher - lower >= x)
			return 1;

		return 0;
	}

	int using_it = bruteForce(it + 1, sum + difficulty[it],
		min(lower, difficulty[it]), max(higher, difficulty[it]));

	int not_using_it = bruteForce(it + 1, sum, lower, higher);

	return using_it + not_using_it;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; ++i)
		cin >> difficulty[i];

	cout << bruteForce(0, 0, INF, -1) << '\n';
}

