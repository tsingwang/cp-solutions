/*
ID: tsing.w2
TASK: ride
LANG: C
*/

#include <stdio.h>

int hash(char *p) {
    int r = 1;

    while (*p != '\0') {
        r = (r * (*p - 'A' + 1)) % 47;
        p++;
    }

    return r;
}

int main() {
    FILE *fin = freopen("ride.in", "r", stdin);
    FILE *fout = freopen("ride.out", "w", stdout);

    char s[7], t[7];
    scanf("%s%s", s, t);

    if (hash(s) == hash(t))
        printf("GO\n");
    else
        printf("STAY\n");

    fclose(fin);
    fclose(fout);

    return 0;
}
