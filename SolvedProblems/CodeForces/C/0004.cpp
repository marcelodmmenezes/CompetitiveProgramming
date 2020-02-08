#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string name;
	unordered_map<string, int> names;

	cin >> n;

	while (n--) {
		cin >> name;

		auto it = names.find(name);

		if (it == names.end()) {
			cout << "OK\n";
			names[name] = 1;
		}
		else {
			name += to_string(it->second);
			++it->second;
			cout << name << '\n';
			names[name] = 1;
		}
	}
}

