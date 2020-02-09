#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	map<string, int> players;

	cin >> n;

	vector<pair<string, int>> rounds(n, pair<string, int>());

	for (auto& it : rounds) {
		cin >> it.first >> it.second;
		players[it.first] += it.second;
	}

	int higher = INT_MIN;

	for (auto& it : players)
		higher = max(higher, it.second);

	map<string, int> replay;

	for (auto& it : rounds) {
		auto& player_pts = replay[it.first];
		player_pts += it.second;

		if (players[it.first] == higher && player_pts >= higher) {
			cout << it.first << '\n';
			break;
		}
	}
}

