#include <bits/stdc++.h>
using namespace std;

int search(int id, vector<int> grafo[], bool visitado[]) {
	visitado[id] = true;

	int n = 1;

	for (int i = 0; i < grafo[id].size(); ++i)
		if (!visitado[grafo[id][i]])
			n += search(grafo[id][i], grafo, visitado);

	return n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char aux_c, v1, v2;
	int n_tests;

	cin >> n_tests;

	while (n_tests--) {
		vector<int> grafo[26];
		bool visitado[26] = { false };

		while (cin >> aux_c && aux_c == '(') {
			cin >> v1 >> aux_c >> v2 >> aux_c;

			grafo[v1 - 'A'].push_back(v2 - 'A');
			grafo[v2 - 'A'].push_back(v1 - 'A');
		}

		cin.ignore(200, '\n');

		int n_trees = 0, n_acorns = 0;

		while ((aux_c = cin.get()) && aux_c != '\n') {
			if (aux_c >= 'A' && aux_c <= 'Z') {
				int id = aux_c - 'A';

				if (!visitado[id]) {
					int count = search(id, grafo, visitado);

					if (count > 1)
						++n_trees;
					else
						++n_acorns;
				}
			}
		}

		cout << "There are " << n_trees << " tree(s) "
			"and " << n_acorns << " acorn(s).\n";
	}
}
