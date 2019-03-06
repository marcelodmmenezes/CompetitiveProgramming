#include <stdio.h>
#include <string.h>

int main() {
	int i = 1;
	char word[20];

	scanf("%s", word);

	while (strcmp(word, "#") != 0) {
		printf("Case %d: ", i++);

		if (strcmp(word, "HELLO") == 0)
			printf("ENGLISH\n");
		else if (strcmp(word, "HOLA") == 0)
			printf("SPANISH\n");
		else if (strcmp(word, "HALLO") == 0)
			printf("GERMAN\n");
		else if (strcmp(word, "BONJOUR") == 0)
			printf("FRENCH\n");
		else if (strcmp(word, "CIAO") == 0)
			printf("ITALIAN\n");
		else if (strcmp(word, "ZDRAVSTVUJTE") == 0)
			printf("RUSSIAN\n");
		else
			printf("UNKNOWN\n");

		scanf("%s", word);
	}

	return 0;
}