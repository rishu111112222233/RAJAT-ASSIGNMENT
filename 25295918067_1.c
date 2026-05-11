#include<stdio.h>
#include <stdlib.h>

void reverseArray(int arr[], int n) {
    int temp;

    for(int i = 0; i<n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
} 
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pivot = arr[high];
 int i = low - 1;

for (int j = low; j < high; j++) {
 if (arr[j] < pivot) {
 i++;

 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
}
 }

 int temp = arr[i + 1];
 arr[i + 1] = arr[high];
arr[high] = temp;

 int pi = i + 1;

 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
    }
}

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(-1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int print_list_forward(Node* node) {

    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }

    return 0;
}
int print_list_backward(Node* head) {

    Node* temp = head;
    if (temp == NULL) {
        return 0;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->prev;
    }

    return 0;
}
int insert_at_beginning(Node** head, int data) {

    Node* new_node = create_node(data);
    new_node->next = *head;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;

    return 0;
}

int main() {
    int n = 5;
    int arr[n];

    printf("\n");

    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("\n ");

    printArray(arr, n);
    
    
    printf("\n ");
    
    quickSort(arr,0,5);
    
    printArray(arr, n);

    Node* head = NULL;
    
    insert_at_beginning(&head, 1);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 0);
    insert_at_beginning(&head, 6);
    insert_at_beginning(&head, 7);
   
    
    printf("\n");
    print_list_forward(head);
    
    printf("\n");
    print_list_backward(head);


    return 0;
}
