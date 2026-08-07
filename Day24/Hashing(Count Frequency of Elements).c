#include <stdio.h>

int main() {
    int n, a[100], freq[101] = {0};

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]]++;
    }

    for(int i = 0; i <= 100; i++) {
        if(freq[i] > 0)
            printf("%d -> %d\n", i, freq[i]);
    }

    return 0;
}
