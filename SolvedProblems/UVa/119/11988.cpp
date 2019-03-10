#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	while (cin >> str) {
		list<char> text;
		list<char>::iterator it = text.begin();

		for (char& c : str) {
			if (c == '[')
				it = text.begin();
			else if (c == ']')
				it = text.end();
			else
				text.insert(it, c);
		}

		for (auto& c: text)
			cout << c;
		cout << '\n';
	}
}
