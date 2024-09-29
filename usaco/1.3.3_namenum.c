/*
ID: tsing.w2
TASK: namenum
LANG: C
*/

#include <stdio.h>

#define N 12

char map[26] = "2223334445556667777888999";

int main() {
    FILE *fin = freopen("namenum.in", "r", stdin);
    FILE *fout = freopen("namenum.out", "w", stdout);

    char num[N+1], word[N+1];
    scanf("%s", num);

    int n = 0;
    FILE *fdict = fopen("dict.txt", "r");
    while (fscanf(fdict, "%s", word) != EOF) {
        char *p, *q;
        for (p = num, q = word; *p != '\0' && *q != '\0'; p++, q++) {
            if (*p != map[*q-'A']) {
                break;
            }
        }
        if ('\0' == *p && '\0' == *q) {
            printf("%s\n", word);
            n++;
        }
    }
    if (0 == n) {
        printf("NONE\n");
    }

    fclose(fin);
    fclose(fout);
    fclose(fdict);
    return 0;
}
