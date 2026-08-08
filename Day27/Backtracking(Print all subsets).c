#include <stdio.h>

void subsets(int arr[], int n, int index, int result[], int size) {
    if (index == n) {
        printf("{ ");
        for (int i = 0; i < size; i++) {
            printf("%d ", result[i]);
        }
        printf("}\n");
        return;
    }

    // Don't take current element
    subsets(arr, n, index + 1, result, size);

    // Take current element
    result[size] = arr[index];
    subsets(arr, n, index + 1, result, size + 1);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;
    int result[3];

    subsets(arr, n, 0, result, 0);

    return 0;
}
