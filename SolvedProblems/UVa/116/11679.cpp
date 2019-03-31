#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int b, n, x, y, z;

	while (cin >> b >> n, b | n) {
		vector<int> v(b);

		for (int i = 0; i < b; ++i)
			cin >> v[i];

		for (int i = 0; i < n; ++i) {
			cin >> x >> y >> z;
			v[x - 1] -= z;
			v[y - 1] += z;
		}

		cout << (count_if(v.begin(), v.end(), [](int i) { return i < 0; }) ?
			"N\n" : "S\n");
	}
}
