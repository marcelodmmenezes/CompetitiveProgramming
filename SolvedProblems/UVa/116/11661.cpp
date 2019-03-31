#include <bits/stdc++.h>
using namespace std;

#define INF 4000000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string highway;

	while (cin >> n, n) {
		int64_t min_dist = INF;
		int64_t last_restaurant = -INF;
		int64_t last_drugstore = -INF;

		cin >> highway;

		for (int i = 0; i < n; ++i) {
			if (highway[i] == 'Z')
				min_dist = 0;
			else if (highway[i] == 'R') {
				min_dist = min(min_dist, i - last_drugstore);
				last_restaurant = i;
			}
			else if (highway[i] == 'D') {
				min_dist = min(min_dist, i - last_restaurant);
				last_drugstore = i;
			}
		}

		cout << min_dist << '\n';
	}
}
