#include <stdio.h>

int main() {
	int i = 1, j, n, treat, aux;

	scanf("%d", &n);

	while (n > 0) {
		treat = 0;

		for (j = 0; j < n; j++) {
			scanf("%d", &aux);
			treat += aux > 0 ? 1 : -1;
		}

		printf("Case %d: %d\n", i++, treat);

		scanf("%d", &n);
	}

	return 0;
}