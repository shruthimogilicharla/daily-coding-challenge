#include <stdio.h>

int main() {
    int a[100], n, key, i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&key);

    for(i=0;i<n;i++) {
        if(a[i]==key) {
            printf("Found at position %d", i+1);
            return 0;
        }
    }

    printf("Not Found");
    return 0;
}
