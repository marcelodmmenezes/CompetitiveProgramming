#include <iostream>

using namespace std;

int main() {
	char c;
	bool open = true;

	while (cin.get(c)) {
		if (c == '\"') {
			if (open)
				cout << "``";
			else
				cout << "\'\'";

			open = !open;
		}
		else
			cout << c;
	}
}