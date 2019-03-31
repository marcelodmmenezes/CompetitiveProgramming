#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;

	cin >> n;

	cout << "Lumberjacks:\n";

	while (n--) {
		bool crescent = true, decrescent = true;

		cin >> x;

		for (int i = 1; i < 10; ++i) {
			cin >> y;

			if (crescent && y < x)
				crescent = false;

			if (decrescent && y > x)
				decrescent = false;

			x = y;
		}

		if (crescent || decrescent)
			cout << "Ordered\n";
		else
			cout << "Unordered\n";
	}
}
