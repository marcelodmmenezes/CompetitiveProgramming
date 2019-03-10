#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;

	char bs[500][500], ss[500][500];

	while (cin >> n >> m, n | m) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> bs[i][j];

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				cin >> ss[i][j];

		n -= m - 1;

		int cont[] = { 0, 0, 0, 0 };

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int r = 0; r < 4; ++r) {
					bool equal = true;

					for (int k = 0; k < m; ++k) {
						for (int l = 0; l < m; ++l) {
							int line, column;

							switch (r) {
							case 0:
								line = k;
								column = l;
								break;

							case 1:
								line = m - l - 1;
								column = k;
								break;

							case 2:
								line = m - k - 1;
								column = m - l - 1;
								break;

							default:
								line = l;
								column = m - k - 1;
							}

							if (bs[i + k][j + l] !=
								ss[line][column]) {
								equal = false;
								k = l = m;
							}
						}
					}

					if (equal)
						++cont[r];
				}
			}
		}

		for (int i = 0; i < 3; ++i)
			cout << cont[i] << ' ';
		cout << cont[3] << '\n';
	}
}
