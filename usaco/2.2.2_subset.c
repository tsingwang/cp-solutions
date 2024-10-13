/*
ID: tsing.w2
TASK: subset
LANG: C
*/

/*
 * DP，设m[i, j]表示取前i个数使set1总数和为j的方案数
 */

#include <stdio.h>

long long m[40][400];

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    int n;
    scanf("%d", &n);

    int sum = (1+n)*n/2;
    if (sum & 1 == 1) {
        printf("0\n");
        return 0;
    }
    sum /= 2;

    m[1][0] = m[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (i <= j) {
                m[i][j] = m[i-1][j] + m[i-1][j-i];
            } else {
                m[i][j] = m[i-1][j];
            }
        }
    }

    printf("%lld\n", m[n][sum]/2);
    return 0;
}
