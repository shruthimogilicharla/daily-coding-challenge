#include <stdio.h>

void quick(int a[], int low, int high)
{
    int i, j, pivot, temp;
    
    if (low < high)
    {
        pivot = a[low];
        i = low + 1;
        j = high;

        while (i <= j)
        {
            while (i <= high && a[i] <= pivot)
                i++;
            while (a[j] > pivot)
                j--;

            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        a[low] = a[j];
        a[j] = pivot;

        quick(a, low, j - 1);
        quick(a, j + 1, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
