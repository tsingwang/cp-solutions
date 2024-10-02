/*
ID: tsing.w2
TASK: milk3
LANG: C
*/

#include <stdio.h>

#define MAX_CAPACITY 20

typedef struct {
    int v[3];
} state_t;

int cap[3];
char seen[MAX_CAPACITY+1][MAX_CAPACITY+1];
char flag[MAX_CAPACITY+1];

state_t state(int a, int b, int c) {
    state_t s = {a, b, c};
    return s;
}

state_t pour(state_t s, int from, int to) {
    int amt = s.v[from];
    if (s.v[to] + amt > cap[to])
        amt = cap[to] - s.v[to];
    s.v[from] -= amt;
    s.v[to] += amt;
    return s;
}

void search(state_t s) {
    if (seen[s.v[0]][s.v[1]])
        return;

    seen[s.v[0]][s.v[1]] = 1;

    if (s.v[0] == 0)
        flag[s.v[2]] = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            search(pour(s, i, j));
        }
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);

    scanf("%d %d %d", &cap[0], &cap[1], &cap[2]);

    search(state(0, 0, cap[2]));

    char *sep = "";
    for (int i = 0; i <= cap[2]; i++) {
        if (flag[i]) {
            printf("%s%d", sep, i);
            sep = " ";
        }
    }
    printf("\n");

    return 0;
}
