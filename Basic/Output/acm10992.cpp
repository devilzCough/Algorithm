#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < (n-i); b++)
            printf(" ");
        if (i == 1)
            printf("*");
        else if (i == n) {
            for (int s = 0; s < 2*i-1; s++)
                printf("*");
        }
        else {
            printf("*");
            for (int b = 0; b < 2*(i-1)-1; b++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
