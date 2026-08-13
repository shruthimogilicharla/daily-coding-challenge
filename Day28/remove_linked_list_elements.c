#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* removeElements(struct Node* head, int val) {
    while (head != NULL && head->val == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}
