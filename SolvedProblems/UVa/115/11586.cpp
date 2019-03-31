#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	cin.get();

	while (n--) {
		int m = 0, f = 0;
		char c;

		while (c = cin.get(), c != '\n') {
			if (c == 'M')
				++m;
			else if (c == 'F')
				++f;
		}

		if (m == f && m > 1)
			cout << "LOOP\n";
		else
			cout << "NO LOOP\n";			
	}
}
