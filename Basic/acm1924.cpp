#include <stdio.h>

int main()
{
    int m, d;
    int total = 0;
    scanf("%d %d", &m, &d);
    for (int i = 1; i < m; i++) {
        if (i == 2)
            total += 28;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            total += 30;
        else
            total += 31;
    }
    total += d;

    int day = total % 7;
    switch(day) {
        case 0:
            printf("SUN\n");
            break;
        case 1:
            printf("MON\n");
            break;
        case 2:
            printf("TUE\n");
            break;
        case 3:
            printf("WED\n");
            break;
        case 4:
            printf("THU\n");
            break;
        case 5:
            printf("FRI\n");
            break;
        case 6:
            printf("SAT\n");
    }
    return 0;
}
