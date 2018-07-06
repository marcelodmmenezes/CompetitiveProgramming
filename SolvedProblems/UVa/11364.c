#include <stdio.h>

int main() {
	int i, t, n, aux, far, near;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		far = 0;
		near = 99;

		for (i = 0; i < n; i++) {
			scanf("%d", &aux);
			near = aux < near ? aux : near;
			far = aux > far ? aux : far;
		}

		printf("%d\n", 2 * (far - near));
	}
}