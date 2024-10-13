/*
ID: tsing.w2
TASK: castle
LANG: C
*/

#include <stdio.h>

#define N       50
#define N_ROOM  (N*N+1)

enum {
    WEST = 1,
    NORTH = 2,
    EAST = 4,
    SOUTH = 8
};

typedef struct {
    int wall;
    int room;
} square_t;

int width, height;
square_t castle[N][N];
int roomsize[N_ROOM];

void mark(int nroom, int y, int x) {
    square_t *p = &castle[y][x];

    if (p->room != 0) {
        return;
    }

    p->room = nroom;
    roomsize[nroom]++;

    if (y > 0 && !(p->wall & NORTH)) {
        mark(nroom, y - 1, x);
    }
    if (x > 0 && !(p->wall & WEST)) {
        mark(nroom, y, x - 1);
    }
    if (y < height - 1 && !(p->wall & SOUTH)) {
        mark(nroom, y + 1, x);
    }
    if (x < width - 1 && !(p->wall & EAST)) {
        mark(nroom, y, x + 1);
    }
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    scanf("%d%d", &width, &height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            scanf("%d", &castle[y][x].wall);
        }
    }

    /* Flood Fill, number rooms */
    int nroom = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (0 == castle[y][x].room) {
                mark(++nroom, y, x);
            }
        }
    }

    int bigroom = roomsize[1];
    for (int i = 2; i <= nroom; i++) {
        if (bigroom < roomsize[i]) {
            bigroom = roomsize[i];
        }
    }

    int max_size = 0, mx, my, mc;
    for (int x = 0; x < width; x++) {
        for (int y = height - 1; y >= 0; y--) {
            if (y > 0 && castle[y][x].room != castle[y-1][x].room) {
                int t = roomsize[castle[y][x].room] + roomsize[castle[y-1][x].room];
                if (max_size < t) {
                    max_size = t;
                    my = y;
                    mx = x;
                    mc = 'N';
                }
            }
            if (x < width - 1 && castle[y][x].room != castle[y][x+1].room) {
                int t = roomsize[castle[y][x].room] + roomsize[castle[y][x+1].room];
                if (max_size < t) {
                    max_size = t;
                    my = y;
                    mx = x;
                    mc = 'E';
                }
            }
        }
    }

    printf("%d\n", nroom);
    printf("%d\n", bigroom);
    printf("%d\n", max_size);
    printf("%d %d %c\n", my+1, mx+1, mc);
    return 0;
}
