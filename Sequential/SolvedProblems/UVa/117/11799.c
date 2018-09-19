#include <stdio.h>

int main() {
	int i, n, n_creatures, creature, max;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &n_creatures);

		max = 0;

		while (n_creatures--) {
			scanf("%d", &creature);
			max = max > creature ? max : creature;
		}

		printf("Case %d: %d\n", i, max);
	}

	return 0;
}