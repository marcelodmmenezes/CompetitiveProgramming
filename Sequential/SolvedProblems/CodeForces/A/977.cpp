#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	while (k--)
		n = n % 10 ? n - 1 : n / 10;

	cout << n << endl;
}