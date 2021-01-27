#include <stdio.h>
#include <string.h>

char str_code[5005];
int code[5005], dp[5005];

int length;

int main()
{
    scanf("%s", str_code);
    length = strlen(str_code);
    // printf("%d\n", length);

    for (int i = length-1; i >=0; i--) {
        code[length-i] = str_code[i] - '0';
        // printf("%d ", code[length-(i+1)]);
    }

    int tmp;
    dp[0] = 1;
    if (code[1] != 0)
        dp[1] = 1;
    for (int i = 2; i <= length; i++) {
        if (code[i] == 0)
            continue;

        dp[i] = dp[i-1];
        tmp = code[i]*10 + code[i-1];
        if (tmp <= 26)
            dp[i] = (dp[i] + dp[i-2]) % 1000000;
    }

    printf("%d\n", dp[length]);
    return 0;
}
