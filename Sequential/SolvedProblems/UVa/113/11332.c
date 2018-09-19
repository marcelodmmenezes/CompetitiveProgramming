#include <stdio.h>
#include <string.h>

int main() {
	int i;
	char n[20];

	scanf("%s", n);

	while (strcmp(n, "0") != 0) {
		int size = strlen(n);

		while (size > 1) {
			int sum = 0;

			for (i = 0; i < size; i++)
				sum += n[i] - '0';

			sprintf(n, "%d", sum);

			size = strlen(n);
		}

		printf("%s\n", n);

		scanf("%s", n);
	}

	return 0;
}