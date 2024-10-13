/*
ID: tsing.w2
TASK: hamming
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define NMAX    64
#define MAX     (1 << 8)

int N, B, D, maxval;
int nums[NMAX], dist[MAX][MAX];

void search(int cur, int start) {
    if (cur == N) {
        for (int i = 0; i < cur; i++) {
            printf("%d", nums[i]);
            if (i % 10 == 9 || i == N - 1)
                printf("\n");
            else
                printf(" ");
        }
        exit(0);
    }

    for (int i = start; i < maxval; i++) {
        int j;
        for (j = 0; j < cur; j++) {
            if (dist[nums[j]][i] < D) {
                break;
            }
        }
        if (j == cur) {
            nums[cur] = i;
            search(cur + 1, i + 1);
        }
    }
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    scanf("%d%d%d", &N, &B, &D);

    maxval = (1 << B);

    for (int i = 0; i < maxval; i++) {
        for (int j = i + 1; j < maxval; j++) {
            //dist[i][j] = 0;
            for (int k = 0; k < B; k++) {
                if (((1 << k) & i) != ((1 << k) & j)) {
                    dist[i][j]++;
                }
            }
        }
    }

    //nums[0] = 0;
    search(1, 1);

    return 0;
}
