/*
ID: tsing.w2
TASK: ariprog
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 125000

int seq[MAX_NUM];
char existed[MAX_NUM+1];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);

    int N, M;
    scanf("%d%d", &N, &M);

    int cnt = 0;
    for (int p = 0; p <= M; p++) {
        for (int q = 0; q <= p; q++) {
            if (!existed[p*p+q*q]) {
                existed[p*p+q*q] = 1;
                seq[cnt++] = p*p + q*q;
            }
        }
    }

    qsort(seq, cnt, sizeof(int), cmp);

    int none = 1;
    int upper = 2*M*M;
    for (int b = 1; b <= upper/(N-1); b++) {
        for (int i = 0; ; i++) {
            int a = seq[i];
            if (a > upper - (N-1)*b)
                break;

            int flag = 1;
            for (int n = 1; n < N; n++) {
                if (!existed[a+n*b]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                none = 0;
                printf("%d %d\n", a, b);
            }
        }
    }

    if (none) printf("NONE\n");
    return 0;
}
