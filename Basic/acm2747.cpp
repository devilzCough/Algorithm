#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int f1 = 0, f2 = 1, fn = 1;

    for (int i = 1; i < n; i++) {
        fn = f1 + f2;
        f1 = f2;
        f2 = fn;
    }

    printf("%d\n", fn);

    return 0;
}
