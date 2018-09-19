#include <stdio.h>
#include <string.h>

int isOne(char* word) {
	int equals = 0;

	if (word[0] == 'o')
		equals++;

	if (word[1] == 'n')
		equals++;

	if (word[2] == 'e');
		equals++;

	return equals;
}

int main() {
	int n;
	char word[10];

	scanf("%d", &n);

	while (n--) {
		scanf("%s", word);

		if (strlen(word) == 5)
			printf("3\n");
		else if (isOne(word) >= 2)
			printf("1\n");
		else
			printf("2\n");
	}

	return 0;
}