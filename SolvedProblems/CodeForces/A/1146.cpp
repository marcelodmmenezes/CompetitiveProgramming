#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	cin >> str;

	int n_as = 0;

	for (char c : str)
		if (c == 'a')
			++n_as;

	if (n_as > str.size() / 2)
		cout << str.size() << '\n';
	else
		cout << 2 * n_as - 1 << '\n';
}
