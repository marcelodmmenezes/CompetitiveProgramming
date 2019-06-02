#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c, d;

	cin >> n;
	++n;

	do {
		a = n % 10;
		b = n / 10 % 10;
		c = n / 100 % 10;
		d = n / 1000 % 10;

		++n;
	}
	while (a == b || a == c || a == d ||
		b == c || b == d || c == d);

	std::cout << n - 1 << std::endl;
}
