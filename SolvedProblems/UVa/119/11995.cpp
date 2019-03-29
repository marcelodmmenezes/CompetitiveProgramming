#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;

	while (cin >> n) {
		bool is_s = true, is_q = true, is_pq = true;
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		while (n--) {
			cin >> x >> y;

			if (is_s) {
				if (x == 1)
					s.push(y);
				else if (!s.empty() && s.top() == y)
					s.pop();
				else
					is_s = false;
			}

			if (is_q) {
				if (x == 1)
					q.push(y);
				else if (!q.empty() && q.front() == y)
					q.pop();
				else
					is_q = false;
			}

			if (is_pq) {
				if (x == 1)
					pq.push(y);
				else if (!pq.empty() && pq.top() == y)
					pq.pop();
				else
					is_pq = false;
			}
		}

		if (is_s && is_q || is_s && is_pq || is_q && is_pq)
			cout << "not sure\n";
		else if (is_s)
			cout << "stack\n";
		else if (is_q)
			cout << "queue\n";
		else if (is_pq)
			cout << "priority queue\n";
		else
			cout << "impossible\n";
	}
}
