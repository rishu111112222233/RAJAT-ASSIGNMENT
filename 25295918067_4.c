#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

struct Node* insertBST(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insertBST(root->left, data);
    else root->right = insertBST(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d", root->data); inorder(root->right); }
}

void postorder(struct Node* root) {
    if (root) { postorder(root->left); postorder(root->right); printf("%d", root->data); }
}

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void heapifyMax(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); heapifyMax(arr, n, largest); }
}

int main() {
    int arr[5], h[5];
    for (int i = 0; i < 5; i++) { scanf("%d", &arr[i]); h[i] = arr[i]; }
    struct Node* root = NULL;
    for (int i = 0; i < 5; i++) root = insertBST(root, arr[i]);
    inorder(root); printf("\n");
    postorder(root); printf("\n");
    for (int i = 5 / 2 - 1; i >= 0; i--) heapifyMax(h, 5, i);
    for (int i = 0; i < 5; i++) printf("%d", h[i]); printf("\n");
    int del = h[0]; h[0] = h[4];
    heapifyMax(h, 4, 0);
    printf("%d\n", del);
    for (int i = 0; i < 4; i++) printf("%d", h[i]); printf("\n");
    return 0;
}
