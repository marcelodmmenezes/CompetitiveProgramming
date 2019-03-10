#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int min_capacity = 0, capacity = 0, a, b;

	while (n--) {
		cin >> a >> b;

		capacity -= a;
		capacity += b;

		if (capacity > min_capacity)
			min_capacity = capacity;
	}

	cout << min_capacity << '\n';
}
