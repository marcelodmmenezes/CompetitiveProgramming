#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k, m, course;

	while (cin >> k, k) {
		cin >> m;

		unordered_set<int> chosen_courses;

		for (int i = 0; i < k; ++i) {
			cin >> course;
			chosen_courses.insert(course);
		}

		int x, y;
		bool possible = true;

		for (int i = 0; i < m; ++i) {
			cin >> x >> y;

			for (int j = 0; j < x; ++j) {
				cin >> course;

				if (chosen_courses.find(course) != chosen_courses.end())
					--y;
			}

			if (y > 0)
				possible = false;
		}

		if (possible)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
