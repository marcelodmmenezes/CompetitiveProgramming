#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007ll

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, ant_at_d = 1, ant_at_abc = 0, new_d, new_abc;

	cin >> n;

	for (long long i = 1; i <= n; ++i) {
		new_d = (ant_at_abc * 3ll) % MOD;
		new_abc = (ant_at_abc * 2ll + ant_at_d) % MOD;
		ant_at_d = new_d;
		ant_at_abc = new_abc;
	}

	cout << ant_at_d << '\n';
}

