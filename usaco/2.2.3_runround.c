/*
ID: tsing.w2
TASK: runround
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m;

int is_runaround(char *s) {
    char t[10];
    strcpy(t, s);

    int len = strlen(t);
    int i = 0;
    while (t[i] != 'X') {
        char ch = t[i];
        t[i] = 'X';
        i = (i + ch - '0') % len;
    }

    /* the string may be all X's and not ended at 0 */
    if (i != 0)
        return 0;

    for (i = 0; i < len; i++) {
        if (t[i] != 'X') {
            return 0;
        }
    }
    return 1;
}

/*
 * create an `md`-digit number in the string `s`.
 * the `used` array keeps track of which digits are already taken.
 * `s` already has `nd` digits.
 */
void permutation(char *s, int *used, int nd, int md) {
    if (nd == md) {
        s[nd] = '\0';
        if (atoi(s) > m && is_runaround(s)) {
            printf("%s\n", s);
            exit(0);
        }
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            s[nd] = '0' + i;
            used[i] = 1;
            permutation(s, used, nd+1, md);
            used[i] = 0;
        }
    }
}

int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);

    scanf("%d", &m);

    char s[10];
    int used[10];
    memset(used, 0, sizeof(used));

    for (int i = 1; i <= 9; i++) {
        permutation(s, used, 0, i);
    }

    return 0;
}
