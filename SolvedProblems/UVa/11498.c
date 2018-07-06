#include <stdio.h>

int main() {
	int i, t, n, m, x, y;

	scanf("%d", &t);

	while (t > 0) {
		scanf("%d%d", &n, &m);

		for (i = 0; i < t; i++) {
			scanf("%d%d", &x, &y);

			if (x > n && y > m)
				printf("NE\n");
			else if (x > n && y < m)
				printf("SE\n");
			else if (x < n && y > m)
				printf("NO\n");
			else if (x < n && y < m)
				printf("SO\n");
			else
				printf("divisa\n");
		}

		scanf("%d", &t);
	}
}