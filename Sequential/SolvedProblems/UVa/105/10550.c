#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, c1, c2, c3;

	scanf("%d%d%d%d", &n, &c1, &c2, &c3);

	while (n || c1 || c2 || c3) {
		int value = 0;

		value += c1 < n ? n - c1 : 40 + n - c1;
		value += c1 < c2 ? c2 - c1 : 40 + c2 - c1;
		value += c3 < c2 ? c2 - c3 : 40 + c2 - c3;

		printf("%d\n", value * 9 + 1080);

		scanf("%d%d%d%d", &n, &c1, &c2, &c3);
	}
}