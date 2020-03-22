#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int b = 0; b < (n-i); b++)
            printf(" ");
        for (int s = 0; s < 2*i-1; s++)
            printf("*");
        printf("\n");
    }
    for (int i = 2; i <= n; i++) {
        for (int b = 0; b < (n-i); b++)
            printf(" ");
        for (int s = 0; s < 2*i-1; s++)
            printf("*");
        printf("\n");
    }
    return 0;
}
