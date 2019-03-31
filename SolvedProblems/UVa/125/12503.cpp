#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n_cases;

	cin >> n_cases;

	while (n_cases--) {
		int n;

		cin >> n;

		int position = 0, id;
		string instruction;
		vector<int> instructions(n);

		for (int i = 0; i < n; ++i) {
			cin >> instruction;

			if (instruction == "LEFT") {
				instructions[i] = -1;
				--position;
			}
			else if (instruction == "RIGHT") {
				instructions[i] = 1;
				++position;
			}
			else {
				cin >> instruction >> id;
				instructions[i] = instructions[id - 1];
				position += instructions[i];
			}
		}

		cout << position << '\n';
	}
}
