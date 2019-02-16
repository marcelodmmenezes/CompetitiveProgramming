#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, size, offset;
	char str[110], aux_c;

	scanf("%d", &n);

	while (n) {
		scanf("%s", str);

		size = strlen(str);
		offset = size / n;

		for (i = 0; i < size; i += offset) {
			for (j = 0; j < offset / 2; j++) {
				aux_c = str[i + j];
				str[i + j] = str[i + offset - j - 1];
				str[i + offset - j - 1] = aux_c;
			}
		}

		printf("%s\n", str);

		scanf("%d", &n);		
	}
}