#include <stdio.h>

int main() {
	int i, n, a, b, c;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &c);

		printf("Case %d: ", i);

		if (a < b && a > c || a > b && a < c)
			printf("%d\n", a);
		else if (b < a && b > c || b > a && b < c)
			printf("%d\n", b);
		else
			printf("%d\n", c);
	}

	return 0;
}