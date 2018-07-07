#include <stdio.h>
#include <string.h>

int main() {
	int n, length;
	char experiment[200];

	scanf("%d", &n);

	while (n--) {
		scanf("%s", &experiment);
		length = strlen(experiment);

		if (length <= 2)
			printf("+\n");
		else if (experiment[length - 2] == '3' && experiment[length - 1] == '5')
			printf("-\n");
		else if (experiment[0] == '9')
			printf("*\n");
		else
			printf("?\n");
	}

	return 0;
}