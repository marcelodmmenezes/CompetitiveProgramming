#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;

	cin >> str;

	for (auto& c : str) {
		c = tolower(c);

		if (c != 'a' && c != 'e' && c != 'i' &&
			c != 'o' && c != 'u' && c != 'y')
			cout << "." << c;
	}

	cout << endl;
}