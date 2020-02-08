#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	cin >> str;

	int n = str.size() - 1;
	bool ab = false, ba = false;

	for (int i = 0; i < n && (!ab || !ba); ++i) {
		if (str[i] == 'A' && str[i + 1] == 'B' && !ab) {
			ab = true;
			++i;
		}
		else if (str[i] == 'B' && str[i + 1] == 'A' && ab) {
			ba = true;
			++i;
		}
	}

	if (ab && ba) {
		cout << "YES\n";
		return 0;
	}

	ab = false, ba = false;

	for (int i = 0; i < n && (!ab || !ba); ++i) {
		if (str[i] == 'A' && str[i + 1] == 'B' && ba) {
			ab = true;
			++i;
		}
		else if (str[i] == 'B' && str[i + 1] == 'A' && !ba) {
			ba = true;
			++i;
		}
	}

	if (ab && ba) {
		cout << "YES\n";
		return 0;
	}
	else
		cout << "NO\n";
}

