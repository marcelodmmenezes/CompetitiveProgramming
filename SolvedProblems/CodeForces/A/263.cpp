#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int v, l, c;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> v;

			if (v) {
				l = i;
				c = j;
			}
		}
	}

	cout << abs(l - 2) + abs(c - 2) << '\n';
}
