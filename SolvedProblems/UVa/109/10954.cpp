#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, v;

	while (cin >> n, n) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < n; ++i) {
			cin >> v;
			pq.push(v);
		}

		int cost = 0, a, b;

		while (!pq.empty()) {
			a = pq.top();
			pq.pop();

			b = pq.top();
			pq.pop();

			a += b;
			cost += a;

			if (!pq.empty())
				pq.push(a);
		}

		cout << cost << endl;
	}
}
