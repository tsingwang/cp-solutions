/*
ID: tsing.w2
TASK: milk2
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define max(m, n) ((m) > (n) ? (m) : (n))

#define N 5000

typedef struct {
    int begin;
    int end;
} line_t;

int cmp(const void *va, const void *vb) {
    line_t *a = (line_t *)va;
    line_t *b = (line_t *)vb;

    if (a->begin > b->begin) {
        return 1;
    } else if (a->begin < b->begin) {
        return -1;
    }
    return 0;
}

int main() {
    FILE *fin = freopen("milk2.in", "r", stdin);
    FILE *fout = freopen("milk2.out", "w", stdout);

    line_t lines[N];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lines[i].begin, &lines[i].end);
    }

    qsort(lines, n, sizeof(line_t), cmp);

    int continuous = 0, idle = 0;
    line_t *p = &lines[0];
    for (int i = 1; i < n; i++) {
        if (lines[i].begin <= p->end) {
            if (lines[i].end > p->end) {
                p->end = lines[i].end;
            }
        } else {
            continuous = max(continuous, p->end - p->begin);
            idle = max(idle, lines[i].begin - p->end);
            p = &lines[i];
        }
    }
    continuous = max(continuous, p->end - p->begin);

    printf("%d %d\n", continuous, idle);

    fclose(fin);
    fclose(fout);
    return 0;
}
