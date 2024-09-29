/*
ID: tsing.w2
TASK: skidesign
LANG: C
*/

#include <stdio.h>

#define min(m, n) ((m) > (n) ? (n) : (m))
#define MAX_N 1000

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int arr[MAX_N];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* try all elevation intervals from (0,17) to (83,100) */
    int mincost = 1000000000;
    for (int i = 0; i <= 83; i++) {
        int cost = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] < i)
                cost += (i - arr[j]) * (i - arr[j]);
            else if (arr[j] > i + 17)
                cost += (arr[j] - i - 17) * (arr[j] - i - 17);
        }
        mincost = min(mincost, cost);
    }
    printf("%d\n", mincost);
    return 0;
}
