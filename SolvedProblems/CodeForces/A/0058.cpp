#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string word, hello("hello");

	cin >> word;

	int id = 0;

	for (int i = 0; i < word.size(); ++i)
		if (word[i] == hello[id])
			++id;

	if (id == hello.size())
		cout << "YES\n";
	else
		cout << "NO\n";
}
