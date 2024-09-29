/*
ID: tsing.w2
TASK: combo
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

int n;

int close(int a, int b) {
    if (abs(a-b) <= 2 || abs(a-b) >= n - 2)
        return 1;
    return 0;
}

int main() {
    FILE *fin = freopen("combo.in", "r", stdin);
    FILE *fout = freopen("combo.out", "w", stdout);

    int a[3], b[3];
    scanf("%d", &n);
    scanf("%d %d %d", a, a+1, a+2);
    scanf("%d %d %d", b, b+1, b+2);

    int total = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if ((close(i, a[0]) && close(j, a[1]) && close(k, a[2])) ||
                        (close(i, b[0]) && close(j, b[1]) && close(k, b[2])))
                    total++;

    printf("%d\n", total);

    fclose(fin);
    fclose(fout);
    return 0;
}
