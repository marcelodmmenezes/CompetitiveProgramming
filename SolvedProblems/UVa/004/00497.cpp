#include <bits/stdc++.h>
using namespace std;

struct Element {
	int id, size, parent;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string line;

	cin >> n;
	getline(cin, line);
	getline(cin, line);

	while (n--) {
		vector<Element> sequence;

		while (getline(cin, line) && line.size() > 0)
			sequence.push_back({ stoi(line), -1, -1 });

		sequence[0].size = 1;

		for (int i = 1; i < sequence.size(); ++i) {
			int j = i - 1;

			while (j >= 0) {
				if (sequence[j].id < sequence[i].id &&
					sequence[j].size + 1 >= sequence[i].size) {
					sequence[i].size = sequence[j].size + 1;
					sequence[i].parent = j;
				}

				--j;
			}
		}

		int max = 0, id;

		for (int i = 0; i < sequence.size(); ++i) {
			if (sequence[i].size > max) {
				max = sequence[i].size;
				id = i;
			}
		}

		stack<int> s;

		while (sequence[id].parent != -1) {
			s.push(sequence[id].id);
			id = sequence[id].parent;
		}

		s.push(sequence[id].id);

		cout << "Max hits: " << s.size() << '\n';

		while (!s.empty()) {
			cout << s.top() << '\n';
			s.pop();
		}

		if (n > 0)
			cout << endl;
	}
}
