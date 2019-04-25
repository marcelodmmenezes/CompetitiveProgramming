/*
 * Fenwick tree (Binary indexed tree) implementation
 * for solving the Range Sum Query problem.
 */


#include <bits/stdc++.h>
using namespace std;


struct FenwickTree {
	vector<int> tree;

	FenwickTree(int n) {
		tree.resize(n + 1, 0); // Tree goes from position 1 to n
	}

	int leastSignificativeOne(int x) {
		return x & -x;
	}

	int rsq(int x) {
		int sum = 0;
		
		++x; // First element of tree is in position 1

		while (x) {
			sum += tree[x];
			x -= leastSignificativeOne(x);
		}

		return sum;
	}

	int rsq(int x, int y) {
		return rsq(y) - rsq(x - 1);
	}

	void add(int x, int v) {
		++x; // First element of tree is in position 1

		while (x < tree.size()) {
			tree[x] += v;
			x += leastSignificativeOne(x);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	///------------------------------------------------------------ Use example
	const int N = 12;

	int input[N] = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };

	FenwickTree ft(N);

	// Creates tree from input
	for (int i = 0; i < N; ++i)
		ft.add(i, input[i]);

	printf("%d\n", ft.rsq(0));      // 2
	printf("%d\n", ft.rsq(N - 1));  // 51
	printf("%d\n", ft.rsq(1));      // 3
	printf("%d\n", ft.rsq(6));      // 16
	printf("%d\n", ft.rsq(2, 6));   // 13 (16 - 3)

	ft.add(3, 3);

	printf("%d\n", ft.rsq(0, 0));      // 2
	printf("%d\n", ft.rsq(0, N - 1));  // 54
	printf("%d\n", ft.rsq(1));         // 3
	printf("%d\n", ft.rsq(6));         // 19
	printf("%d\n", ft.rsq(2, 6));      // 16 (19 - 3)
}
