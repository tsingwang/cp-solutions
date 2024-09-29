/*
ID: tsing.w2
TASK: transform
LANG: C
*/

#include <stdio.h>

#define N 10

typedef struct {
    int n;
    char m[N][N];
} board_t;

board_t rotate(board_t b) {
    board_t nb;
    nb.n = b.n;
    for (int r = 0; r < b.n; r++) {
        for (int c = 0; c < b.n; c++) {
            nb.m[c][b.n-1-r] = b.m[r][c];
        }
    }
    return nb;
}

board_t reflect(board_t b) {
    board_t nb;
    nb.n = b.n;
    for (int r = 0; r < b.n; r++) {
        for (int c = 0; c < b.n; c++) {
            nb.m[r][b.n-1-c] = b.m[r][c];
        }
    }
    return nb;
}

int equal(board_t nb, board_t b) {
    if (b.n != nb.n)
        return 0;

    for (int r = 0; r < b.n; r++) {
        for (int c = 0; c < b.n; c++) {
            if (b.m[r][c] != nb.m[r][c]) {
                return 0;
            }
        }
    }

    return 1;
}

board_t read_board(int n) {
    board_t b;
    b.n = n;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            b.m[r][c] = getchar();
        }
        getchar();
    }
    return b;
}

int main() {
    FILE *fin = freopen("transform.in", "r", stdin);
    FILE *fout = freopen("transform.out", "w", stdout);

    int n;
    scanf("%d\n", &n);
    board_t b = read_board(n);
    board_t nb = read_board(n);

    int ret;
    if (equal(nb, rotate(b))) {
        ret = 1;
    } else if (equal(nb, rotate(rotate(b)))) {
        ret = 2;
    } else if (equal(nb, rotate(rotate(rotate(b))))) {
        ret = 3;
    } else if (equal(nb, reflect(b))) {
        ret = 4;
    } else if (equal(nb, rotate(reflect(b)))
            || equal(nb, rotate(rotate(reflect(b))))
            || equal(nb, rotate(rotate(rotate(reflect(b)))))) {
        ret = 5;
    } else if (equal(nb, b)) {
        ret = 6;
    } else {
        ret = 7;
    }

    printf("%d\n", ret);

    fclose(fin);
    fclose(fout);
    return 0;
}
