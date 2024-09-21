/*
ID: tsing.w2
TASK: beads
LANG: C
*/

#include <stdio.h>
#include <string.h>

#define max(m, n) ((m) > (n) ? (m) : (n))
#define min(m, n) ((m) > (n) ? (n) : (m))

int main() {
    FILE *fin = freopen("beads.in", "r", stdin);
    FILE *fout = freopen("beads.out", "w", stdout);

    int n;
    char s[800], tmp[400];
    scanf("%d%s", &n, tmp);
    strcpy(s, tmp);
    strcat(s, tmp);

    int left_r[800], left_b[800];
    left_r[0] = left_b[0] = 0;
    for (int i = 1; i <= 2*n; i++) {
        if ('r' == s[i-1]) {
            left_r[i] = left_r[i-1] + 1;
            left_b[i] = 0;
        } else if ('b' == s[i-1]) {
            left_r[i] = 0;
            left_b[i] = left_b[i-1] + 1;
        } else {
            left_r[i] = left_r[i-1] + 1;
            left_b[i] = left_b[i-1] + 1;
        }
    }

    int right_r[800], right_b[800];
    right_r[2*n] = right_b[2*n] = 0;
    for (int i = 2*n - 1; i >= 0; i--) {
        if ('r' == s[i]) {
            right_r[i] = right_r[i+1] + 1;
            right_b[i] = 0;
        } else if ('b' == s[i]) {
            right_r[i] = 0;
            right_b[i] = right_b[i+1] + 1;
        } else {
            right_r[i] = right_r[i+1] + 1;
            right_b[i] = right_b[i+1] + 1;
        }
    }

    int ans = 0;
    for (int i = 1; i < 2*n; i++) {
        ans = max(ans, max(left_r[i], left_b[i]) + max(right_r[i], right_b[i]));
    }
    printf("%d\n", min(ans, n));

    fclose(fin);
    fclose(fout);

    return 0;
}
