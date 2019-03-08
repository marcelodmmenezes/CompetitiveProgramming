#include <bits/stdc++.h>
using namespace std;

struct Soldier {
	int left;
	int right;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int s, b;

	while (cin >> s >> b, s | b) {
		vector<Soldier> soldiers(s);

		for (int i = 0; i < s; i++) {
			soldiers[i].left = i - 1;
			soldiers[i].right = i + 1;
		}

		soldiers[s - 1].right = -1;

		int l, r;

		while (b--) {
			cin >> l >> r;
			--l;
			--r;

			if (soldiers[l].left == -1 && soldiers[r].right == -1)
				cout << "* *\n";
			else if (soldiers[l].left == -1) {
				cout << "* " << soldiers[r].right + 1 << '\n';
				soldiers[soldiers[r].right].left = -1;
			}
			else if (soldiers[r].right == -1) {
				cout << soldiers[l].left + 1 << " *\n";
				soldiers[soldiers[l].left].right = -1;
			}
			else {
				cout << soldiers[l].left + 1
					<< ' ' << soldiers[r].right + 1 << '\n';
				soldiers[soldiers[l].left].right = soldiers[r].right;
				soldiers[soldiers[r].right].left = soldiers[l].left;
			}

		}
		
		cout << "-\n";
	}
}
