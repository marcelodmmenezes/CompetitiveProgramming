#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int zeros = 0, ones = 0;
	bool dangerous = false;

	cin >> str;

	for (auto c : str) {
		if (c == '1') {
			++ones;
			zeros = 0;

			if (ones == 7) {
				dangerous = true;
				break;
			}
		}
		else {
			++zeros;
			ones = 0;

			if (zeros == 7) {
				dangerous = true;
				break;
			}
		}
	}

	if (dangerous)
		cout << "YES\n";
	else
		cout << "NO\n";
}
