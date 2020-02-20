#include <bits/stdc++.h>

using namespace std;

int n, k;
string str;

int check(char a, char b) {
	int higher = 1, sum = 1, k_count = 0, i = 0, j = 1;

	if (str[i] == b)
		++k_count;

	while (j < n) {
		if (str[j] == b) {
			++k_count;

			if (k_count > k) {
				while (str[i] != b && i < n) {
					++i;
					--sum;
				}

				if (i == n)
					return higher;

				++i;
				--k_count;
			}
			else
				++sum;
		}
		else
			++sum;

		higher = max(higher, sum);

		++j;
	}

	return higher;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> str;

	if (k == 0) {
		int max_a = 1, max_b = 1, c_a = 0, c_b = 0;

		for (int i = 0; i < n; ++i) {
			if (str[i] == 'a') {
				++c_a;
				max_b = max(max_b, c_b);
				c_b = 0;
			}
			else {
				++c_b;
				max_a = max(max_a, c_a);
				c_a = 0;
			}
		}

		max_a = max(max_a, c_a);
		max_b = max(max_b, c_b);

		cout << max(max_a, max_b) << '\n';
	}
	else
		cout << max(check('a', 'b'), check('b', 'a')) << '\n';
}

