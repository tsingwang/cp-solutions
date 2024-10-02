/*
ID: tsing.w2
TASK: pprime
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int is_prime(int n) {
    if (n == 2) return 1;
    if (n%2 == 0) return 0;
    for (int i = 3; i*i <= n; i += 2)
        if (n%i == 0)
            return 0;
    return 1;
}

int gen_pal(int n, int is_odd_digits) {
    int pal = n;
    if (is_odd_digits)
        n /= 10;

    while (n > 0) {
        pal = pal*10 + n%10;
        n /= 10;
    }
    return pal;
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    int a, b;
    scanf("%d%d", &a, &b);

    int primes[10000], n = 0;
    for (int i = 1; i < 9999; i++) {
        for (int j = 0; j < 2; j++) {
            int num = gen_pal(i, j);
            if (num >= a && num <= b && is_prime(num))
                primes[n++] = num;
        }
    }

    qsort(primes, n, sizeof(int), cmp);

    for (int i = 0; i < n; i++)
        printf("%d\n", primes[i]);

    return 0;
}
