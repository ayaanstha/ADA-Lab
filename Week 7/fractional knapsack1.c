#include <stdio.h>
#include <stdlib.h>


struct Item {
    int value, weight;
};


int compare(const void *a, const void *b) {
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r2 > r1) - (r2 < r1);
}


double fractionalKnapsack(int W, struct Item arr[], int n) {

    qsort(arr, n, sizeof(struct Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W == 0)
            break;

        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return totalValue;
}


int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    double maxValue = fractionalKnapsack(W, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
