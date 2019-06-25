#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	while (cin >> n, n) {
		int max = 0, in, sum = 0;

		for (int i = 0; i < n; ++i) {
			cin >> in;

			sum += in;

			if (sum < 0)
				sum = 0;

			if (sum > max)
				max = sum;
		}

		if (max == 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << max << ".\n";
	}	
}
