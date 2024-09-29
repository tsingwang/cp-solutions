/*
ID: tsing.w2
TASK: dualpal
LANG: C
*/

#include <stdio.h>
#include <string.h>

void num_convert(char *s, int n, int base) {
    while (n > 0) {
        int d = n % base;
        if (d >= 0 && d <= 9) {
            *s++ = d + '0';
        } else {
            *s++ = d + 'A' - 10;
        }
        n /= base;
    }
    *s = '\0';
}

int is_pal(char *s) {
    for (char *t = s + strlen(s) - 1; s < t; s++, t--) {
        if (*s != *t) {
            return 0;
        }
    }
    return 1;
}

int main() {
    FILE *fin = freopen("dualpal.in", "r", stdin);
    FILE *fout = freopen("dualpal.out", "w", stdout);

    int n, s;
    scanf("%d %d", &n, &s);

    char num[50];
    while (n > 0) {
        s++;
        int cnt = 0;
        for (int base = 2; base <= 10; base++) {
            num_convert(num, s, base);
            if (is_pal(num)) {
                if (++cnt > 1) {
                    break;
                }
            }
        }
        if (cnt > 1) {
            printf("%d\n", s);
            n--;
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
