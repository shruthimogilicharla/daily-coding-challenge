#include <stdio.h>

int main() {
    int n, temp, rev = 0, r;

    scanf("%d", &n);
    temp = n;

    while(n > 0) {
        r = n % 10;
        rev = rev * 10 + r;
        n /= 10;
    }

    if(temp == rev)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
