/*
ID: tsing.w2
TASK: barn1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define N 200

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    FILE *fin = freopen("barn1.in", "r", stdin);
    FILE *fout = freopen("barn1.out", "w", stdout);

    int arr[N];
    int m, s, c;
    scanf("%d %d %d", &m, &s, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, c, sizeof(int), cmp);

    s = arr[c-1] - arr[0] + 1;

    for (int i = 0; i < c - 1; i++) {
        arr[i] = arr[i+1] - arr[i];
    }
    qsort(arr, c - 1, sizeof(int), cmp);

    /* cautious! */
    if (m < c) {
        for (int i = 0; i < m - 1; i++) {
            s -= arr[c-2-i] - 1;
        }
    } else {
        s = c;
    }

    printf("%d\n", s);

    fclose(fin);
    fclose(fout);
    return 0;
}
