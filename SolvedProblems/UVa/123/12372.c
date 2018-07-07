#include <stdio.h>

int main() {
	int i, n, x, y, z;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &z);

		if (x > 20 || y > 20 || z > 20)
			printf("Case %d: bad\n", i);
		else
			printf("Case %d: good\n", i);
	}

	return 0;
}