#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_cases;

	cin >> n_cases;

	while (n_cases--) {
		int n, low, high;
		string name;

		cin >> n;

		vector<tuple<string, int, int>> makers(n);

		for (int i = 0; i < n; ++i) {
			cin >> name >> low >> high;
			makers[i] = make_tuple(name, low, high);
		}

		int m, price;

		cin >> m;

		while (m--) {
			cin >> price;

			int cont = 0;

			for (auto& it : makers) {
				if (get<1>(it) <= price && price <= get<2>(it)) {
					name = get<0>(it);
					++cont;
				}

				if (cont > 1)
					break;
			}

			if (cont == 1)
				cout << name << '\n';
			else
				cout << "UNDETERMINED\n";
		}

		if (n_cases) cout << '\n';
	}
}
