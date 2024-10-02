/*
ID: tsing.w2
TASK: sprime
LANG: C
*/

#include <stdio.h>

int highest_digits[4] = {2, 3, 5, 7};
int other_digits[4] = {1, 3, 7, 9};

int is_prime(int n) {
    if (n == 2) return 1;
    if (n%2 == 0) return 0;
    for (int i = 3; i*i <= n; i += 2)
        if (n%i == 0)
            return 0;
    return 1;
}

void search(int n, int ndigit) {
    if (!is_prime(n)) return;

    if (ndigit == 0) {
        printf("%d\n", n);
        return;
    }

    for (int i = 0; i < 4; i++) {
        search(n*10 + other_digits[i], ndigit - 1);
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < 4; i++) {
        search(highest_digits[i], n - 1);
    }

    return 0;
}
