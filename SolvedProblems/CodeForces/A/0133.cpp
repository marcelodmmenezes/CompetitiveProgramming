#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string p;

	cin >> p;

	for (auto& c : p) {
		if (c == 'H' || c == 'Q' || c == '9') {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
}
