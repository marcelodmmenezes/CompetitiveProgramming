#include <stdio.h>

typedef struct {
	int dist;
	char grande;
} Pedra;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int t, n, d, i, id = 1ll;
	Pedra pedras[110];

	scanf("%d", &t);

	while (t--) {
		scanf("%d %d%*c", &n, &d);

		pedras[0].dist = 0;
		pedras[n + 1].dist = d;
		pedras[0].grande = pedras[n + 1].grande = 'B';

		for (i = 1; i <= n; i++)
			scanf("%c%*c%d%*c", &pedras[i].grande, &pedras[i].dist);

		int maior = 0;

		for (i = 0; i <= n; i++) {
			if (pedras[i + 1].grande == 'B')
				maior = max(maior, pedras[i + 1].dist - pedras[i].dist);
			else
				maior = max(maior, pedras[i + 2].dist - pedras[i].dist);
		}

		printf("Case %d: %d\n", id++, maior);
	}
}