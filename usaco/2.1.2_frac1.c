/*
ID: tsing.w2
TASK: frac1
LANG: C
*/

#include <stdio.h>

int n;

void gen(int u1, int d1, int u2, int d2) {
    if (d1 + d2 > n) {
        return;
    }

    gen(u1, d1, u1 + u2, d1 + d2);
    printf("%d/%d\n", u1 + u2, d1 + d2);
    gen(u1 + u2, d1 + d2, u2, d2);
}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);

    scanf("%d", &n);

    printf("0/1\n");
    gen(0, 1, 1, 1);
    printf("1/1\n");

    return 0;
}
