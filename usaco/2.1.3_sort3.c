/*
ID: tsing.w2
TASK: sort3
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    int arr[N], sort[N];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sort[i] = arr[i];
    }

    qsort(sort, n, sizeof(int), cmp);

    /* swaps that correct two elements */
    int nswap2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == sort[i]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == sort[i] && arr[i] == sort[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                nswap2++;
            }
        }
    }

    /* remainder are pairs of swaps that correct three elements */
    int nswap3 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != sort[i]) {
            nswap3++;
        }
    }

    printf("%d\n", nswap2 + nswap3/3*2);

    return 0;
}
