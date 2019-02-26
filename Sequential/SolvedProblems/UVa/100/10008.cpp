#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<char, int>& p1, pair<char, int>& p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;

	return p1.second > p2.second;
}

int main() {
	int n;
	pair<char, int> letters[26];
	string line;

	for (int i = 0; i < 26; i++)
		letters[i] = make_pair('A' + i, 0);

	scanf("%d", &n);
	getchar();

	while (n--) {
		getline(cin, line);

		for (char c : line) {
			if (c >= 'A' && c <= 'Z')
				letters[c - 'A'].second++;
			else if (c >= 'a' && c <= 'z')
				letters[c - 'a'].second++;
		}
	}

	sort(letters, letters + 26, cmp);

	for (int i = 0; i < 26; i++)
		if (letters[i].second > 0)
			cout << letters[i].first << " " << letters[i].second << "\n";
}