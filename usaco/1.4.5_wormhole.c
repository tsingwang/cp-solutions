/*
ID: tsing.w2
TASK: wormhole
LANG: C
*/

#include <stdio.h>

#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int partner[MAX_N+1];
int next_on_right[MAX_N+1];

int cycle_exists() {
    for (int i = 1; i <= N; i++) {
        int pos = i;
        for (int cnt = 0; cnt < N; cnt++)
            pos = next_on_right[partner[pos]];
        if (pos != 0) return 1;
    }
    return 0;
}

int solve() {
    int cnt = 0, i;

    /* find first unpaired wormhole */
    for (i = 1; i <= N; i++)
        if (partner[i] == 0)
            break;

    if (i > N) {
        if (cycle_exists()) return 1;
        else return 0;
    }

    for (int j = i + 1; j <= N; j++) {
        if (partner[j] == 0) {
            partner[i] = j;
            partner[j] = i;
            cnt += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return cnt;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &X[i], &Y[i]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (Y[i] == Y[j] && X[i] < X[j])
                if (next_on_right[i] == 0 || X[j] < X[next_on_right[i]])
                    next_on_right[i] = j;
        }
    }

    printf("%d\n", solve());

    return 0;
}
