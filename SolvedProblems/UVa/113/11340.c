#include <stdio.h>

int main() {
    int n_cases;

    scanf("%d", &n_cases);

    while (n_cases--) {
        int aux_i, i;
        long long chars[256] = {}, aux_ll, value = 0;
        char line[10001];

        scanf("%d ", &aux_i);

        while(aux_i--) {
            gets(line);
            sscanf(line + 2, "%lld", &aux_ll);
            chars[line[0] + 128] = aux_ll;
        }

        scanf("%d ", &aux_i);

        while(aux_i--) {
            gets(line);
            for(i = 0; line[i]; i++)
                value += chars[line[i] + 128];
        }

        printf("%lld.%02lld$\n", value / 100, value % 100);
    }

    return 0;
}