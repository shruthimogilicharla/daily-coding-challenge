#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(int arr[], int start, int n) {
    if (start == n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++) {
        swap(&arr[start], &arr[i]);

        permutations(arr, start + 1, n);

        // Backtrack
        swap(&arr[start], &arr[i]);
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    permutations(arr, 0, n);

    return 0;
}
