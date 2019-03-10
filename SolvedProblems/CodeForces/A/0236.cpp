#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string name;
	set<char> unique;

	cin >> name;

	for (auto c : name)
		unique.insert(c);

	if (unique.size() & 1)
		cout << "IGNORE HIM!\n";
	else
		cout << "CHAT WITH HER!\n";
}
