#include <stdio.h>

int main() {
	int n, w, h;

	scanf("%d", &n);

	while (n--) {
		scanf("%d %d", &w, &h);
		printf("%d\n", (w / 3) * (h / 3));
	}
}