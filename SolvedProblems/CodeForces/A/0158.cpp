#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, v, value, cont = 0;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> value;

		if (value > 0)
			cont++;
	}

	for (int i = k; i < n; i++) {
		cin >> v;

		if (v == value && v > 0)
			cont++;
	}

	cout << cont << endl;
}
