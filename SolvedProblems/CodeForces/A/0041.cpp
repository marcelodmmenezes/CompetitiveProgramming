#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string word, translation;

	cin >> word >> translation;

	bool correct = true;

	int n = word.size();

	if (n != translation.size())
		correct = false;
	else {
		for (int i = 0; i < n; ++i) {
			if (word[i] != translation[n - i - 1]) {
				correct = false;
				break;
			}
		}
	}

	if (correct)
		cout << "YES\n";
	else
		cout << "NO\n";
}
