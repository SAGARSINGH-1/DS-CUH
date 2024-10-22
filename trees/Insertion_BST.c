#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *InsertNode(struct node *root, int data)
{

    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = InsertNode(root->left, data);
    }
    else
    {
        root->right = InsertNode(root->right, data);
    }
    return root;
}

void deleteNode(struct node *root, int data)
{
    
}

void InOrderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    printf("%d -> ", root->data);
    InOrderTraversal(root->right);
}

void PreOrderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d -> ", root->data);
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    printf("%d -> ", root->data);
}

int main()
{
    int choice;
    while (1)
    {
        printf("Enter the choice : ");
        printf("\n1. Insertion into BST\n2.Inorder traversal\n3.Preorder traversal\n4.Postorder traversal\n5. Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int data;
            printf("Enter the data : ");
            scanf("%d", &data);
            root = InsertNode(root, data);
            break;
        case 2:
            printf("Inorder traversal: ");
            InOrderTraversal(root);
            break;
        case 3:
            printf("PreOrder traversal: ");
            PreOrderTraversal(root);
            break;
        case 4:
            printf("Postorder traversal: ");
            PostOrderTraversal(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Chose from given option.");
            break;
        }
    }
}
