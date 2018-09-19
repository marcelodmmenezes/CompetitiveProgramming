#include <stdio.h>
#include <stdlib.h>

int main() {
	int n_cases, n_columns, y1, y2, max_dif, min_dif;

	scanf("%d", &n_cases);

	while (n_cases--) {
		scanf("%d", &n_columns);

		max_dif = -1000;
		min_dif = 1000;

		while (n_columns--) {
			scanf("%d%d", &y1, &y2);

			int dif = abs(y1 - y2);

			max_dif = max_dif > dif ? max_dif : dif;
			min_dif = min_dif < dif ? min_dif : dif;
		}

		if (min_dif == max_dif)
			puts("yes");
		else
			puts("no");

		if (n_cases > 0)
			puts("");
	}

	return 0;
}