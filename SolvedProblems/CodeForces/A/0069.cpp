#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y, z, s_x = 0, s_y = 0, s_z = 0;

	cin >> n;

	while (n--) {
		cin >> x >> y >> z;
		s_x += x;
		s_y += y;
		s_z += z;
	}

	if (!s_x && !s_y && !s_z)
		cout << "YES\n";
	else
		cout << "NO\n";
}
