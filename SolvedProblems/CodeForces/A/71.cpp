#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string word;

	cin >> n;

	while (n--) {
		cin >> word;

		if (word.size() > 10)
			cout << word[0] << word.size() - 2 << word.back() << "\n";
		else
			cout << word << "\n";
	}
}
