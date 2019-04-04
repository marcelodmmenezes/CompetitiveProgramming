#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, count = 0, p, q;

	cin >> n;

	while (n--) {
		cin >> p >> q;

		if (q - p >= 2)
			++count;
	}

	cout << count << '\n';
}
