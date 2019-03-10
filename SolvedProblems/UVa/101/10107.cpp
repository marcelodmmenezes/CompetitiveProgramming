#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<int> v;

	while (cin >> n) {
		v.push_back(n);

		int aux, i = v.size() - 1;

		while (i > 0 && v[i] < v[i - 1]) {
			aux = v[i];
			v[i] = v[i - 1];
			v[i - 1] = aux;
			i--;
		}

		if (v.size() & 1)
			cout << v[v.size() / 2] << '\n';
		else
			cout << (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2 << '\n';
	}
}
