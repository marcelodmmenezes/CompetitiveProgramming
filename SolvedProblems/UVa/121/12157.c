#include <stdio.h>
#include <math.h>

int main() {
	int n, n_calls, i, j;
	double call, mile, juice;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &n_calls);

		mile = juice = 0.0;

		for (j = 0; j < n_calls; j++) {
			scanf("%lf", &call);
			mile += ceil((call + 1) / 30.0) * 10;
			juice += ceil((call + 1) / 60.0) * 15;
		}

		if (mile < juice)
			printf("Case %d: Mile %d\n", i, (int)mile);
		else if (mile == juice)
			printf("Case %d: Mile Juice %d\n", i, (int)mile);
		else
			printf("Case %d: Juice %d\n", i, (int)juice);
	}
}