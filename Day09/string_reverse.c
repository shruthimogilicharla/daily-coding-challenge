#include <stdio.h>

int main() {
    char str[100];
    int i, len = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[len] != '\0')
        len++;

    printf("Reversed String = ");

    for (i = len - 1; i >= 0; i--)
        printf("%c", str[i]);

    printf("\n");

    return 0;
}
