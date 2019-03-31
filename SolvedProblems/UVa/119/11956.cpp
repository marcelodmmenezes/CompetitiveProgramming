#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << right << uppercase << setfill('0');

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int pointer = 0;
		string line;
		vector<int> memory(100, 0);

		cout << dec << "Case " << i << ':';

		cin >> line;

		for (auto it : line) {
			switch (it) {
				case '>':
					pointer = (pointer + 1) % 100;
					break;

				case '<':
					pointer = (pointer + 99) % 100;
					break;

				case '+':
					memory[pointer] = (memory[pointer] + 1) % 256;
					break;

				case '-':
					memory[pointer] = (memory[pointer] + 255) % 256; 
					break;
			}
		}

		cout << hex;

		for (auto it : memory)
			cout << ' ' << setw(2) << it;
		cout << '\n';
	}
}
