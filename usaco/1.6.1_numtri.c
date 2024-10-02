/*
ID: tsing.w2
TASK: numtri
LANG: C
*/

#include <stdio.h>

#define N 1000

#define max(m, n) ((m) > (n) ? (m) : (n))

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    int n;
    int m[N][N];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            m[i][j] += max(m[i+1][j], m[i+1][j+1]);
        }
    }

    printf("%d\n", m[0][0]);

    return 0;
}
