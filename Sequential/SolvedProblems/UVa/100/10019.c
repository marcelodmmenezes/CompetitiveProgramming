#include <stdio.h>

int countOnesBin(int x) {
    int i = 0, n_ones = 0;

    while (x > 0) {
        n_ones += x % 2;
        x /= 2; 
        i++;
    }

    return n_ones;
}

int main() {
	int n, m, h;
	char hex[32];

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &m);

		sprintf(hex, "%d", m);
		sscanf(hex, "%x", &h);

		printf("%d %d\n", countOnesBin(m), countOnesBin(h));
	}
}