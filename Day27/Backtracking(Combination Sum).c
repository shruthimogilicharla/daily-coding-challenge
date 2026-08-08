#include <stdio.h>

void combinationSum(int arr[], int n, int target,
                    int index, int result[], int size) {

    if (target == 0) {
        printf("[ ");
        for (int i = 0; i < size; i++) {
            printf("%d ", result[i]);
        }
        printf("]\n");
        return;
    }

    if (target < 0 || index == n) {
        return;
    }

    // Take current element
    result[size] = arr[index];
    combinationSum(arr, n, target - arr[index],
                   index, result, size + 1);

    // Don't take current element
    combinationSum(arr, n, target,
                   index + 1, result, size);
}

int main() {
    int arr[] = {2, 3, 6, 7};
    int n = 4;
    int target = 7;
    int result[100];

    combinationSum(arr, n, target, 0, result, 0);

    return 0;
}
