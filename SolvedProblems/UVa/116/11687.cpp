#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	while (cin >> str, str != "END") {
		int n_digits, n, m, i = 1;

		n_digits = str.size();

		if (str != "1") {
			do {
				n = n_digits;
				n_digits = 0;
				m = n;

				while (m) {
					m /= 10;
					++n_digits;
				}

				++i;
			}
			while (n != n_digits);
		}

		cout << i << endl;
	}
}
