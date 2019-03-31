#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;

	while (cin >> a >> b, a >= 0) {
		if (a <= b)
			cout << min(b - a, a + 100 - b) << '\n';
		else
			cout << min(a - b, b + 100 - a) << '\n';
	}
}
