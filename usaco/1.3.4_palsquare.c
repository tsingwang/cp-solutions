/*
ID: tsing.w2
TASK: palsquare
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

void reverse(char *s) {
    for (char *t = s + strlen(s) - 1; s < t; s++, t--) {
        char ch = *s;
        *s = *t;
        *t = ch;
    }
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
    FILE *fin = freopen("palsquare.in", "r", stdin);
    FILE *fout = freopen("palsquare.out", "w", stdout);

    int base;
    scanf("%d", &base);

    char s[20], t[20];
    for (int n = 1; n <= 300; n++) {
        num_convert(t, n*n, base);
        if (is_pal(t)) {
            num_convert(s, n, base);
            reverse(s);
            printf("%s %s\n", s, t);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
