#include <stdio.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int l = 2*i+1, r = 2*i+2, m = i;
    if (l < n && a[l] > a[m]) m = l;
    if (r < n && a[r] > a[m]) m = r;
    if (m != i) {
        int t = a[i]; a[i] = a[m]; a[m] = t;
        heapify(a, n, m);
    }
}

void sort(int a[], int n) {
    for (int i = n/2-1; i >= 0; i--) heapify(a, n, i);
    for (int i = n-1; i > 0; i--) {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapify(a, i, 0);
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    printf("How many numbers: ");
    scanf("%d", &n);
    printf("Enter the numbers: ");
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    clock_t s = clock();
    sort(a, n);
    clock_t e = clock();
    print(a, n);
    printf("Time: %.6f sec\n", (double)(e-s)/CLOCKS_PER_SEC);
    return 0;
}
