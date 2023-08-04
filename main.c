#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    struct tm firstDay = { .tm_year = year - 1900, .tm_mon = 0, .tm_mday = 1 };
    mktime(&firstDay);

    printf("\nCALENDAR %d\n", year);

    for (int month = 0; month < 12; month++) {
        struct tm currentDay = firstDay;

        currentDay.tm_mon = month;
        mktime(&currentDay);

        printf("\n%s\n", asctime(&currentDay));
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        int weekday = currentDay.tm_wday;

        for (int i = 0; i < weekday; i++) {
            printf("    ");
        }

        int daysInMonth = 31 - (month == 1) - (month == 3 || month == 5 || month == 8 || month == 10);

        for (int day = 1; day <= daysInMonth; day++) {
            printf("%3d ", day);

            if (++weekday > 6) {
                weekday = 0;
                printf("\n");
            }
        }

        printf("\n");
    }

    return 0;
}
