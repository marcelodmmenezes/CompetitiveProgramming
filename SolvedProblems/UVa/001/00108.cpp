#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int matrix[110][110];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];

			if (i > 0)
				matrix[i][j] += matrix[i - 1][j];

			if (j > 0)
				matrix[i][j] += matrix[i][j - 1];

			if (i > 0 && j > 0)
				matrix[i][j] -= matrix[i - 1][j - 1];
		}
	}

	int max = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = i; k < n; ++k) {
				for (int l = j; l < n; ++l) {
					int sum = matrix[k][l];

					if (i > 0)
						sum -= matrix[i - 1][l];

					if (j > 0)
						sum -= matrix[k][j - 1];

					if (i > 0 && j > 0)
						sum += matrix[i - 1][j - 1];

					if (sum > max)
						max = sum;
				}
			}
		}
	}

	cout << max << '\n';
}
