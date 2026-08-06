#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

int main()
{
    int a[] = {4, 10, 3, 5, 1};
    int n = 5;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    printf("Max Heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
