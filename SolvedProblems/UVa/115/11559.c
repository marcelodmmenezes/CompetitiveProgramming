#include <stdio.h>

int main() {
	int i, n_participants, budget, n_hotels, n_weeks, price, room;

	while (scanf("%d%d%d%d", &n_participants, &budget, &n_hotels, &n_weeks) != EOF) {
		int min = budget + 1;

		while (n_hotels--) {
			scanf("%d", &price);

			for (i = 0; i < n_weeks; i++) {
				scanf("%d", &room);

				if (n_participants * price < min && room >= n_participants)
					min = n_participants * price;
			}
		}

		if (min <= budget)
			printf("%d\n", min);
		else
			printf("stay home\n");
	}

	return 0;
}