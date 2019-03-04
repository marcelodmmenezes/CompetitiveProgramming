#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int numbers[] = { 0, 0, 0 };
	string equation;

	cin >> equation;

	for (auto c : equation)
		if (c != '+')
			++numbers[c - '1'];

	for (int i = 0; i < 3; ++i) {
		if (numbers[i]) {
			if (i == 1 && numbers[0] ||
				i == 2 && (numbers[0] || numbers[1]))
				cout << '+';

			cout << i + 1;
		}

		for (int j = 1; j < numbers[i]; ++j)
			cout << '+' << i + 1;
	}

	cout << endl;
}
