#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str, last_digits = "";

	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		last_digits += str[i];

		if (last_digits == "8" || last_digits == "0") {
			cout << "YES\n" << last_digits << '\n';
			return 0;
		}

		for (int j = i + 1; j < str.size(); ++j) {
			last_digits += str[j];

			if (stoi(last_digits) % 8 == 0) {
				cout << "YES\n" << last_digits << '\n';
				return 0;
			}

			for (int k = j + 1; k < str.size(); ++k) {
				last_digits += str[k];

				if (stoi(last_digits) % 8 == 0) {
					cout << "YES\n" << last_digits << '\n';
					return 0;
				}

				last_digits.pop_back();
			}

			last_digits.pop_back();
		}

		last_digits.pop_back();
	}

	cout << "NO\n";
}

