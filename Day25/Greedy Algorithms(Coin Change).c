#include <stdio.h>

int main() {
    int coins[] = {100, 50, 20, 10, 5, 2, 1};
    int amount;

    scanf("%d", &amount);

    for(int i = 0; i < 7; i++) {
        while(amount >= coins[i]) {
            printf("%d ", coins[i]);
            amount -= coins[i];
        }
    }

    return 0;
}
