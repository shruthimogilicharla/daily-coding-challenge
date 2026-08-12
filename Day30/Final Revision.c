#include <stdio.h>

int main() {
    int a[] = {10, 20, 30, 40, 50};
    int n = 5, key = 30, i, found = 0;

    // Linear Search
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("Linear Search: Element found at index %d\n", i);
    else
        printf("Linear Search: Element not found\n");

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    // Binary Search
    int low = 0, high = n - 1, mid;
    key = 40;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            printf("Binary Search: Element found at index %d\n", mid);
            return 0;
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Binary Search: Element not found\n");

    return 0;
}
