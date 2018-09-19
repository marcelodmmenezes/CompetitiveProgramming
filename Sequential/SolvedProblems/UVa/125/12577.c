#include <stdio.h>
#include <string.h>

int main() {
	int i = 1;
	char hajj[10];

	scanf("%s", hajj);

	while (strlen(hajj) > 1) {
		if (strcmp(hajj, "Hajj") == 0)
			printf("Case %d: Hajj-e-Akbar\n", i++);
		else
			printf("Case %d: Hajj-e-Asghar\n", i++);

		scanf("%s", hajj);
	}

	return 0;
}