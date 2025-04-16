#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir;
} Element;

void printPerm(Element *perm, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i].value);
    printf("\n");
}

int getMobile(Element *perm, int n) {
    int mobile = -1;
    for (int i = 0; i < n; i++) {
        int next = i + perm[i].dir;
        if (next >= 0 && next < n && perm[i].value > perm[next].value) {
            if (mobile == -1 || perm[i].value > perm[mobile].value)
                mobile = i;
        }
    }
    return mobile;
}

void generatePermutations(int n) {
    Element *perm = malloc(n * sizeof(Element));
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    printPerm(perm, n);

    while (1) {
        int i = getMobile(perm, n);
        if (i == -1) break;

        int j = i + perm[i].dir;
        Element tmp = perm[i]; perm[i] = perm[j]; perm[j] = tmp;

        for (int k = 0; k < n; k++)
            if (perm[k].value > perm[j].value)
                perm[k].dir *= -1;

        printPerm(perm, n);
    }

    free(perm);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    generatePermutations(n);
    return 0;
}
