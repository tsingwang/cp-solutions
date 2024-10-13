/*
ID: tsing.w2
TASK: holstein
LANG: C
*/

#include <stdio.h>
#include <string.h>

#define NV 25
#define NG 15

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);

    int nv, ng;
    int req[NV], feeds[NG][NV];

    scanf("%d", &nv);
    for (int i = 0; i < nv; i++) {
        scanf("%d", &req[i]);
    }
    scanf("%d", &ng);
    for (int i = 0; i < ng; i++) {
        for (int j = 0; j < nv; j++) {
            scanf("%d", &feeds[i][j]);
        }
    }

    int best = ng + 1, best_choice, feed[NV];
    for (int i = 1; i < (1 << ng); i++) {
        memset(feed, 0, sizeof(feed));
        int cnt = 0;
        for (int j = 0; j < ng; j++) {
            if ((i & (1 << j)) != 0) {
                cnt++;
                for (int k = 0; k < nv; k++) {
                    feed[k] += feeds[j][k];
                }
            }
        }

        int j;
        for (j = 0; j < nv; j++) {
            if (feed[j] < req[j]) {
                break;
            }
        }
        if (j == nv) {
            if (best > cnt) {
                best = cnt;
                best_choice = i;
            }
        }
    }

    printf("%d", best);
    for (int i = 0; i < ng; i++) {
        if ((best_choice & (1 << i)) != 0) {
            printf(" %d", i + 1);
        }
    }
    printf("\n");
    return 0;
}
