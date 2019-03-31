#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 0;
	string str;

	while (cin >> str) {
		cout << "Case " << ++t << ":\n";

		vector<int> v(str.size());

		v[0] = str[0] - '0';

		for (int i = 1; i < str.size(); ++i)
			v[i] = v[i - 1] + (str[i] - '0');

		int n, x, y;

		cin >> n;

		while (n--) {
			cin >> x >> y;

			if (x > y)
				swap(x, y);

			if (str[y] == str[x] && (v[y] - v[x] == y - x || v[y] == v[x]))
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}
