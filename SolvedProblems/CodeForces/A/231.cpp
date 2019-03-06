#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, cont = 0;

	cin >> n;

	while (n--) {
		int s, sure = 0;

		for (int i = 0; i < 3; i++) {
			cin >> s;
			sure += s;
		}

		if (sure >= 2)
			cont++;
	}

	cout << cont << endl;
}
