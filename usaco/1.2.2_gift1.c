/*
ID: tsing.w2
TASK: gift1
LANG: C
*/

#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 10
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN+1];
    int total;
} person_t;

person_t persons[MAX_PEOPLE];
int n;

person_t* lookup(char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(persons[i].name, name) == 0) {
            return &persons[i];
        }
    }
}

int main() {
    FILE *fin = freopen("gift1.in", "r", stdin);
    FILE *fout = freopen("gift1.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", persons[i].name);
        persons[i].total = 0;
    }

    char name[NAME_LEN+1];
    while (scanf("%s", name) != EOF) {
        person_t *giver = lookup(name);
        int amt, ng;
        scanf("%d %d", &amt, &ng);
        for (int i = 0; i < ng; i++) {
            scanf("%s", name);
            person_t *receiver = lookup(name);
            receiver->total += amt/ng;
            giver->total -= amt/ng;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", persons[i].name, persons[i].total);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
