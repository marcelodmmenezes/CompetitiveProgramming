#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string code;

	while (cin >> code, code != "#") {
		if (next_permutation(code.begin(), code.end()))
			cout << code << '\n';
		else
			cout << "No Successor\n";
	}
}
