#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, n, w;

	cin >> k >> n >> w;

	cout << max(0, ((w * (w + 1)) / 2) * k - n) << '\n';
}
