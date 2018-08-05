#include <stdio.h>

int main() {
	int i, loan_duration, n_records, month, last_month, found, resp;
	double payment, loan, deprecation, last_deprecation, car_value, tax;

	scanf("%d%lf%lf%d", &loan_duration, &payment, &loan, &n_records);

	while (loan_duration > 0) {
		resp = 0;
		found = 0;
		car_value = loan + payment;
		tax = loan / loan_duration;
		loan += tax;

		scanf("%d%lf", &last_month, &last_deprecation);

		for (i = 1; i < n_records; i++) {
			scanf("%d%lf", &month, &deprecation);

			while (!found && last_month < month) {
				car_value *= 1.0 - last_deprecation;
				loan -= tax;

				if (car_value > loan) {
					resp = last_month;
					found = 1;
				}
				
				last_month++;
			}

			last_month = month;
			last_deprecation = deprecation;
		}

		while (car_value <= loan) {
			car_value *= 1.0 - last_deprecation;
			loan -= tax;
			resp = last_month++;
		}

		if (resp == 1)
			printf("1 month\n");
		else
			printf("%d months\n", resp);

		scanf("%d%lf%lf%d", &loan_duration, &payment, &loan, &n_records);
	}

	return 0;
}