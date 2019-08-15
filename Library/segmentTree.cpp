/*
 * Segment tree implementation
 * for solving the Range Sum Query problem.
 */

#include <bits/stdc++.h>
using namespace std;


#define N 12


int segtree[4 * N + 1];

void buildTree(int arr[], int v, int node_l, int node_r) {
	if (node_l == node_r)
		segtree[v] = arr[node_l];
	else {
		int m = (node_l + node_r) / 2;

		buildTree(arr, v * 2, node_l, m);
		buildTree(arr, v * 2 + 1, m + 1, node_r);

		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
	}
}

int queryTree(int v, int node_l, int node_r, int query_l, int query_r) {
	if (query_l > query_r)
		return 0;

	if (query_l == node_l && query_r == node_r)
		return segtree[v];

	int m = (node_l + node_r) / 2;

	return queryTree(v * 2, node_l, m, query_l, min(query_r, m)) +
		queryTree(v * 2 + 1, m + 1, node_r, max(query_l, m + 1), query_r);
}

void updateTree(int v, int node_l, int node_r, int pos, int value) {
	if (node_l == node_r)
		segtree[v] = value;
	else {
		int m = (node_l + node_r) / 2;

		if (pos <= m)
			updateTree(v * 2, node_l, m, pos, value);
		else
			updateTree(v * 2 + 1, m + 1, node_r, pos, value);

		segtree[v] = segtree[v * 2] + segtree[v * 2 + 1];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	///------------------------------------------------------------ Use example
	int input[N] = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };

	// Creates tree from input
	buildTree(input, 1, 0, N - 1);

	printf("%d\n", queryTree(1, 0, N - 1, 0, 0));           // 2
	printf("%d\n", queryTree(1, 0, N - 1, 0, N - 1));       // 51
	printf("%d\n", queryTree(1, 0, N - 1, 0, 1));           // 3
	printf("%d\n", queryTree(1, 0, N - 1, 0, 6));           // 16
	printf("%d\n", queryTree(1, 0, N - 1, 2, 6));           // 13 (16 - 3)

	updateTree(1, 0, N - 1, 3, 6);

	printf("%d\n", queryTree(1, 0, N - 1, 0, 0));         // 2
	printf("%d\n", queryTree(1, 0, N - 1, 0, N - 1));     // 54
	printf("%d\n", queryTree(1, 0, N - 1, 0, 1));         // 3
	printf("%d\n", queryTree(1, 0, N - 1, 0, 6));         // 19
	printf("%d\n", queryTree(1, 0, N - 1, 2, 6));         // 16 (19 - 3)
}
