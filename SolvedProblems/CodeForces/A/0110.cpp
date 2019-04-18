#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long n, n_fours = 0, n_sevens = 0;

	cin >> n;

	while (n) {
		if (n % 10 == 4)
			++n_fours;
		else if (n % 10 == 7)
			++n_sevens;

		n /= 10;
	}

	n = n_fours + n_sevens;

	if (n == 4 || n == 7)
		cout << "YES\n";
	else
		cout << "NO\n";
}
