#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, v, groups[4] = { 0 };

	cin >> n;

	while (n--) {
		cin >> v;
		++groups[v - 1];
	}

	n = groups[3] + groups[2] + groups[1] / 2;

	if (groups[1] & 1) {
		++n;
		groups[0] -= 2;
	}

	groups[0] -= groups[2];

	if (groups[0] > 0)
		n += (groups[0] + 3) / 4;

	cout << n << '\n';
}
