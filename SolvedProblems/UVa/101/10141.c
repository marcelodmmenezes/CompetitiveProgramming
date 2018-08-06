#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, p, i, j, n_requirements_met, compliance, count = 1;
	char name[81], aux_name[81], aux_input;
	float price, aux_price;

	scanf("%d%d", &n, &p);

	while (n > 0) {
		compliance = 0;

		getchar();
		for (i = 0; i < n; i++)
			while (getchar() != '\n');

		for (i = 0; i < p; i++) {
			j = 0;
			while ((aux_input = getchar()) != '\n') {
				aux_name[j] = aux_input;
				j++;
			}
			aux_name[j] = '\0';

			scanf("%f %d", &aux_price, &n_requirements_met);

			if (n_requirements_met > compliance ||
				n_requirements_met == compliance && aux_price < price) {
				strcpy(name, aux_name);
				price = aux_price;
				compliance = n_requirements_met;
			}

			getchar();
			for (j = 0; j < n_requirements_met; j++)
				while (getchar() != '\n');
		}

		printf("RFP #%d\n%s\n", count++, name);

		scanf("%d%d", &n, &p);

		if (n > 0)
			puts("");
	}

	return 0;
}