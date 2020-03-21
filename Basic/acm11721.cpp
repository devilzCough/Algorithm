#include <stdio.h>

int main()
{
    char line[105];
    int i = 0;
    scanf("%s", line);
    while (line[i]) {
        printf("%c", line[i++]);
        if (i%10 == 0)
            printf("\n");
    }
    return 0;
}
