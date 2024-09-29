/*
ID: tsing.w2
TASK: crypt1
LANG: C
*/

#include <stdio.h>

char digits[10];

int check(int n, int wide) {
    while (n > 0) {
        if (!digits[n%10]) {
            return 0;
        }
        n /= 10;
        wide--;
    }
    if (wide != 0) {
        return 0;
    }
    return 1;
}

int main() {
    FILE *fin = freopen("crypt1.in", "r", stdin);
    FILE *fout = freopen("crypt1.out", "w", stdout);

    int n, m;
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d", &m);
        digits[m] = 1;
    }

    int ret = 0;
    for (int i = 111; i < 1000; i++) {
        for (int j = 11; j < 100; j++) {
            if (check(i, 3) && check(j, 2) && check(i*j, 4)
                    && check(i*(j%10), 3) && check(i*(j/10), 3)) {
                ret++;
            }
        }
    }
    printf("%d\n", ret);

    fclose(fin);
    fclose(fout);
    return 0;
}
