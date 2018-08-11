#include <stdio.h>
#include <string.h>

int main() {
	int n, i, a, b, absolut;
	int arr[3010];

	while (scanf("%d", &n) != EOF) {
		memset(arr, 0, n * sizeof(int));

		scanf("%d", &a);

		for (i = 1; i < n; i++) {
			scanf("%d", &b);
			absolut = abs(a - b);

			if (absolut < n)
				arr[absolut] = 1;

			a = b;
		}

		for (i = 1; i < n; i++)
			if (!arr[i])
				break;

		if (i == n)
			puts("Jolly");
		else
			puts("Not jolly");
	}

	return 0;
}