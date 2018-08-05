#include <stdio.h>

int main() {
	int n, n_farmers, farm_size, n_animals, env_friend;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &n_farmers);

		int sum = 0;

		while (n_farmers--) {
			scanf("%d%d%d", &farm_size, &n_animals, &env_friend);
			sum += farm_size * env_friend;
		}

		printf("%d\n", sum);
	}

	return 0;
}