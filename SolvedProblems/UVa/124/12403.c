#include <stdio.h>

int main() {
	int n, aux, amount = 0;
	char command[10];

	scanf("%d", &n);

	while (n--) {
		scanf("%s", command);

		if (command[0] == 'd') {
			scanf("%d", &aux);
			amount += aux;
		}
		else
			printf("%d\n", amount);
	}

	return 0;
}