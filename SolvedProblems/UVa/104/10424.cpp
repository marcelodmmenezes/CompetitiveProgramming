#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(2);

	string n, m;

	while (getline(cin, n), getline(cin, m)) {
		int value_n = 0, value_m = 0;

		transform(n.begin(), n.end(), n.begin(), ::tolower);
		transform(m.begin(), m.end(), m.begin(), ::tolower);

		for (int i = 0; i < n.size(); ++i)
			value_n += n[i] >= 'a' && n[i] <= 'z' ? n[i] - 'a' + 1 : 0;

		for (int i = 0; i < m.size(); ++i)
			value_m += m[i] >= 'a' && m[i] <= 'z' ? m[i] - 'a' + 1 : 0;

		int aux_n = 0, aux_m = 0;

		while (value_n) {
			aux_n += value_n % 10;
			value_n /= 10;

			if (!value_n && aux_n / 10) {
				value_n = aux_n;
				aux_n = 0;
			}
		}

		value_n = aux_n;

		while (value_m) {
			aux_m += value_m % 10;
			value_m /= 10;

			if (!value_m && aux_m / 10) {
				value_m = aux_m;
				aux_m = 0;
			}
		}

		value_m = aux_m;

		if (value_m < value_n)
			swap(value_n, value_m);

		cout << 100.0 * value_n / value_m << " %\n";
	}
}
