#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, r = 0, g = 0, b = 0, cont = 0;
	char c;

	cin >> n;

	while (n--) {
		cin >> c;

		if (c == 'R') {
			r++;
			if (g > 1) cont += g - 1;
			if (b > 1) cont += b - 1;
			g = b = 0;
		}
		else if (c == 'G') {
			g++;
			if (r > 1) cont += r - 1;
			if (b > 1) cont += b - 1;
			r = b = 0;
		}
		else {
			b++;
			if (r > 1) cont += r - 1;
			if (g > 1) cont += g - 1;
			r = g = 0;
		}
	}

	if (r > 1) cont += r - 1;
	if (g > 1) cont += g - 1;
	if (b > 1) cont += b - 1;

	cout << cont << '\n';
}
