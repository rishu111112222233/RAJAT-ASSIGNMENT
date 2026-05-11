#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Node* q[100];
    int lvls[100], vNodes[5], vLvls[5];
    int f = 0, r = 0, c = 0;
    q[r] = root; lvls[r++] = 1;
    while (f < r) {
        struct Node* curr = q[f];
        int currL = lvls[f++];
        vNodes[c] = curr->data; vLvls[c++] = currL;
        if (curr->left) { q[r] = curr->left; lvls[r++] = currL + 1; }
        if (curr->right) { q[r] = curr->right; lvls[r++] = currL + 1; }
    }
    printf("Level of Nodes ");
    for (int i = 0; i < c; i++) printf("%d%s", vNodes[i], (i == c - 1 ? "" : ", "));
    printf(" = ");
    for (int i = 0; i < c; i++) printf("L%d%s", vLvls[i], (i == c - 1 ? "" : ", "));
    printf("\n");
}

int postOrderMetrics(struct Node* root, int depth) {
    if (root == NULL) return -1;
    int lh = postOrderMetrics(root->left, depth + 1);
    int rh = postOrderMetrics(root->right, depth + 1);
    int h = (lh > rh ? lh : rh) + 1;
    printf("Height of Node %d = H%d, Depth of Node %d = Y%d\n", root->data, h + 1, root->data, depth + 1);
    return h;
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);
    struct Node* root = NULL;
    for (int i = 0; i < 5; i++) root = insert(root, arr[i]);
    inorder(root); printf("\n");
    preorder(root); printf("\n");
    levelOrder(root);
    postOrderMetrics(root, 0);
    return 0;
}
