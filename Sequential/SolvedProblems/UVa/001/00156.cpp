#include <bits/stdc++.h>
using namespace std;

int main() {
	string word;
	vector<string> words;
	map<string, int> ananagrams;

	while (cin >> word, word != "#") {
		words.push_back(word);

		string ananagram(word);
		transform(word.begin(), word.end(), ananagram.begin(), ::tolower);
		sort(ananagram.begin(), ananagram.end());

		auto search = ananagrams.find(ananagram);

		if (search == ananagrams.end())
			ananagrams[ananagram] = 0;
		else
			search->second++;
	}

	sort(words.begin(), words.end());

	for (auto& it : words) {
		string ananagram(it);
		transform(it.begin(), it.end(), ananagram.begin(), ::tolower);
		sort(ananagram.begin(), ananagram.end());

		if (ananagrams.find(ananagram)->second == 0)
			cout << it << "\n";
	}
}