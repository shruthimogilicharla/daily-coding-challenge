#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    struct Node *temp = search(root->left, key);
    if (temp != NULL)
        return temp;

    return search(root->right, key);
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(struct Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main()
{
    struct Node *root = NULL;
    int choice, value, parent;

    while (1)
    {
        printf("\n------ Binary Tree ------\n");
        printf("1. Create Root\n");
        printf("2. Insert Left Child\n");
        printf("3. Insert Right Child\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Search Element\n");
        printf("8. Count Nodes\n");
        printf("9. Count Leaf Nodes\n");
        printf("10. Height of Tree\n");
        printf("11. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                printf("Enter root value: ");
                scanf("%d", &value);
                root = createNode(value);
            }
            else
            {
                printf("Root already exists.\n");
            }
            break;

        case 2:
        {
            printf("Enter parent node value: ");
            scanf("%d", &parent);

            struct Node *p = search(root, parent);

            if (p == NULL)
            {
                printf("Parent not found.\n");
            }
            else if (p->left != NULL)
            {
                printf("Left child already exists.\n");
            }
            else
            {
                printf("Enter left child value: ");
                scanf("%d", &value);
                p->left = createNode(value);
            }
            break;
        }

        case 3:
        {
            printf("Enter parent node value: ");
            scanf("%d", &parent);

            struct Node *p = search(root, parent);

            if (p == NULL)
            {
                printf("Parent not found.\n");
            }
            else if (p->right != NULL)
            {
                printf("Right child already exists.\n");
            }
            else
            {
                printf("Enter right child value: ");
                scanf("%d", &value);
                p->right = createNode(value);
            }
            break;
        }

        case 4:
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Enter value to search: ");
            scanf("%d", &value);

            if (search(root, value))
                printf("Element Found\n");
            else
                printf("Element Not Found\n");
            break;

        case 8:
            printf("Total Nodes = %d\n", countNodes(root));
            break;

        case 9:
            printf("Leaf Nodes = %d\n", countLeaves(root));
            break;

        case 10:
            printf("Height = %d\n", height(root));
            break;

        case 11:
            exit(0);

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
