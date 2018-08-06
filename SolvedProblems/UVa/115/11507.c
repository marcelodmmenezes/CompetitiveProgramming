#include <stdio.h>

int main() {
	int n, pos;
	char a, b;

	scanf("%d", &n);

	while (n > 0) {
		getchar();

		pos = 0;

		while (--n) {
			scanf("%c%c", &a, &b);
			getchar();

			if (a == '+') {
				if (b == 'z') {
					if (pos == 0) pos = 1;
					else if (pos == 1) pos = 5;
					else if (pos == 3) pos = 0;
					else if (pos == 5) pos = 3;
				}
				else {
					if (pos == 0) pos = 2;
					else if (pos == 2) pos = 5;
					else if (pos == 4) pos = 0;
					else if (pos == 5) pos = 4;
				}
			}
			else if (a == '-') {
				if (b == 'z') {
					if (pos == 0) pos = 3;
					else if (pos == 1) pos = 0;
					else if (pos == 3) pos = 5;
					else if (pos == 5) pos = 1;
				}
				else {
					if (pos == 0) pos = 4;
					else if (pos == 2) pos = 0;
					else if (pos == 4) pos = 5;
					else if (pos == 5) pos = 2;
				}
			}
		}
		
		if (pos == 0) puts("+x");
		else if (pos == 1) puts("+z");
		else if (pos == 2) puts("+y");
		else if (pos == 3) puts("-z");
		else if (pos == 4) puts("-y");
		else puts("-x");

		scanf("%d", &n);
	}

	return 0;
}