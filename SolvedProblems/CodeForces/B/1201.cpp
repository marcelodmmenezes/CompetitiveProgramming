#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long sum = 0ll, higher = 0ll, x;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x;
		sum += x;
		higher = max(higher, x);
	}

	if (sum % 2 == 0 && higher <= sum - higher)
		cout << "YES\n";
	else
		cout << "NO\n";
}
