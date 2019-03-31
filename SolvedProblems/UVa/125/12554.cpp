#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;

	string song[] = {
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you",
	};

	cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int n_words = sizeof(song) / sizeof(string);

	for (int i = 0; i < n || i % n_words != 0; ++i)
		cout << v[i % n] << ": " << song[i % n_words] << '\n';
}
