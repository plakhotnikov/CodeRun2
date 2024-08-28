// 23. Две команды


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a, b, n;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);
    int maxA = a;
    int minB = (b % n == 0 ? b / n : b / n + 1);
    if (maxA > minB) {
        printf("Yes");
    }
    else {
        printf("No");
    }

     return 0;
}
