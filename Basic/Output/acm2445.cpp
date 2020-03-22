#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        for (int s = 0; s < i; s++)
            printf("*");
        for (int b = 0; b < (n-i)*2; b++)
            printf(" ");
        for (int s = 0; s < i; s++)
                printf("*");
        printf("\n");
    }
    for (int i = n; i > 0; i--) {
        for (int s = 0; s < i; s++)
            printf("*");
        for (int b = 0; b < (n-i)*2; b++)
            printf(" ");
        for (int s = 0; s < i; s++)
            printf("*");
        printf("\n");
    }
    return 0;
}
