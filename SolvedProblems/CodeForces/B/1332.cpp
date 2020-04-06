#include <bits/stdc++.h>
using namespace std;

inline int gcd(int a, int b) {
	if (a == 0)
		return b;

	return gcd(b % a, a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;

	cin >> t;

	while (t--) {
		int n;

		cin >> n;

		vector<int> elements(n);
		vector<int> colors(n);

		int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

		map<int, int> color_map;
		int color_id = 1;

		for (int i = 0; i < n; ++i) {
			cin >> elements[i];

			for (int j = 0; j < 11; ++j) {
				if (elements[i] % primes[j] == 0) {
					auto color_it = color_map.find(j);

					if (color_it == color_map.end())
						color_map[j] = colors[i] = color_id++;
					else
						colors[i] = color_it->second;

					break;
				}
			}
		}

		cout << color_id - 1 << '\n' << colors[0];

		for (int i = 1; i < n; ++i)
			cout << ' ' << colors[i];

		cout << '\n';
	}
}

