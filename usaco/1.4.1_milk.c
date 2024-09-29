/*
ID: tsing.w2
TASK: milk
LANG: C
*/

#include <stdio.h>

#define MAX_PRICE 1000

int main() {
    FILE *fin = freopen("milk.in", "r", stdin);
    FILE *fout = freopen("milk.out", "w", stdout);

    int amts[MAX_PRICE+1] = {0};
    int n, m, price, amount;
    scanf("%d %d", &n, &m);
    while (m-- > 0) {
        scanf("%d %d", &price, &amount);
        amts[price] += amount;
    }

    int sum = 0, cost = 0;
    for (price = 0; price <= MAX_PRICE; price++) {
        if (sum + amts[price] <= n) {
            sum += amts[price];
            cost += price * amts[price];
        } else {
            cost += price * (n - sum);
            break;
        }
    }
    printf("%d\n", cost);

    fclose(fin);
    fclose(fout);
    return 0;
}
