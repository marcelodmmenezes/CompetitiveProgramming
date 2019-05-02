#include <bits/stdc++.h>
using namespace std;

#define N 100
#define M 100

int n, m;
char graph[N][M];

// 8 neighbours
int dr[] = {  1,  1,  0, -1, -1, -1,  0,  1 };
int dc[] = {  0,  1,  1,  1,  0, -1, -1, -1 };

int flood(int r, int c, char c1, char c2) {
	if (r < 0 || r >= n || c < 0 || c >= m)
		return 0;

	if (graph[r][c] != c1)
		return 0;

	graph[r][c] = c2;
	int res = 1;

	for (int i = 0; i < 8; ++i)
		res += flood(r + dr[i], c + dc[i], c1, c2);

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> graph[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (graph[i][j] == 'W')
				cout << flood(i, j, 'W', '.') << ' ';

	cout << '\n';

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << graph[i][j];
		cout << '\n';
	}
}
