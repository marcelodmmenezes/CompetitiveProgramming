#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int height, length;

	while (cin >> height, height) {
		cin >> length;

		int n = 0, x, y;

		cin >> x;

		for (int i = 1; i < length; ++i) {
			cin >> y;
			n += max(0, y - x);
			x = y;
		}

		n += max(0, height - x);

		cout << n << '\n';
	}
}
