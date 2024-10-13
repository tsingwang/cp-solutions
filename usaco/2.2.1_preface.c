/*
ID: tsing.w2
TASK: preface
LANG: C
*/

#include <stdio.h>
#include <string.h>

static char *encode[] = {
    "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
    "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
    "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
    "M", "MM", "MMM"
};

char* roman(int n) {
    static char buf[20];

    strcpy(buf, "");
    if (n % 10 != 0) {
        strcat(buf, encode[n%10 - 1]);
    }
    n /= 10;
    if (n % 10 != 0) {
        strcat(buf, encode[n%10 + 8]);
    }
    n /= 10;
    if (n % 10 != 0) {
        strcat(buf, encode[n%10 + 17]);
    }
    n /= 10;
    if (n > 0) {
        strcat(buf, encode[n + 26]);
    }

    return buf;
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    int n, cnt[256] = {0};
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (char *p = roman(i); *p; p++) {
            cnt[*p]++;
        }
    }

    for (char *p = "IVXLCDM"; *p; p++) {
        if (cnt[*p]) {
            printf("%c %d\n", *p, cnt[*p]);
        }
    }

    return 0;
}
