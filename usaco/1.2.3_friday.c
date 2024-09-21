/*
ID: tsing.w2
TASK: friday
LANG: C
*/

#include <stdio.h>

int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int is_leap_year(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main() {
    FILE *fin = freopen("friday.in", "r", stdin);
    FILE *fout = freopen("friday.out", "w", stdout);

    int weeks[7] = {0}; /* Sat, Sun, Mon, ..., Fri */
    int cursor = 2;     /* January 1, 1900 was on a Monday. */
    int n;

    scanf("%d", &n);
    for (int y = 1900; y < 1900 + n; y++) {
        if (is_leap_year(y)) {
            mon[1] = 29;
        }
        for (int m = 0; m < 12; m++) {
            weeks[(cursor+12)%7]++;
            cursor += mon[m];
        }
        mon[1] = 28;
    }

    for (int i = 0; i < 7; i++) {
        if (i) printf(" ");
        printf("%d", weeks[i]);
    }
    printf("\n");

    fclose(fin);
    fclose(fout);

    return 0;
}
