#include <stdio.h>

int main() {
	int h, d, f, success;
	float u;

	scanf("%d%f%d%d", &h, &u, &d, &f);

	while (h > 0) {
		int i = 1;
		float pos = 0, factor = f * u / 100.0f;

		while (pos < h) {
			pos += u;

			if (pos > h) {
				success = 1;
				break;
			}

			pos -= d;
			u -= factor;

			if (u < 0.0f)
				u = 0.0f;

			if (pos < 0) {
				success = 0;
				break;
			}

			i++;
		}

		if (success)
			printf("success on day %d\n", i);
		else
			printf("failure on day %d\n", i);

		scanf("%d%f%d%d", &h, &u, &d, &f);
	}

	return 0;
}