#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	string queue;

	cin >> n >> t >> queue;

	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (queue[j] == 'B' && queue[j + 1] == 'G') {
				swap(queue[j], queue[j + 1]);
				++j;
			}
		}
	}

	cout << queue << '\n';
}
