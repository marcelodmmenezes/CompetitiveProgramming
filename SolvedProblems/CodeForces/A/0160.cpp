#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, total = 0;

	cin >> n;

	vector<int> coins(n);

	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
		total += coins[i];
	}

	sort(coins.begin(), coins.end(), greater<int>());

	int cont = 0, sum = 0;

	while (sum <= total) {
		sum += coins[cont];
		total -= coins[cont];
		cont++;
	}

	cout << cont << endl;
}
