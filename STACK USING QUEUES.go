#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define URL_SIZE 100

// Stack structure
typedef struct {
    char data[MAX][URL_SIZE];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
}

// Check empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push
void push(Stack *s, char url[]) {
    if (s->top < MAX - 1) {
        strcpy(s->data[++(s->top)], url);
    }
}

// Pop
char* pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return NULL;
}

// Clear stack
void clear(Stack *s) {
    s->top = -1;
}

// Print stack from bottom to top
void printStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%s\n", s->data[i]);
    }
}

int main() {
    Stack backStack, forwardStack;
    char current[URL_SIZE] = "";
    char input[URL_SIZE];

    init(&backStack);
    init(&forwardStack);

    printf("A new browsing session has started.\n\n");

    // Stage 0
    printf("NEW SESSION\n");

    while (1) {
        printf("\n----------------------------------\n");

        // Show current page
        if (strlen(current) == 0) {
            printf("CURRENT: NEW SESSION\n");
        } else {
            printf("CURRENT: %s\n", current);
        }

        // BACK option
        if (isEmpty(&backStack)) {
            printf("BACK (NO PREVIOUS PAGES)\n");
        } else {
            printf("BACK\n");
        }

        // NEXT option
        if (isEmpty(&forwardStack)) {
            printf("NEXT (NO FURTHER PAGES)\n");
        } else {
            printf("NEXT\n");
        }

        printf("Enter URL / BACK / NEXT / PRINT HISTORY:\n");
        fgets(input, URL_SIZE, stdin);

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        // BACK operation
        if (strcmp(input, "BACK") == 0) {
            if (isEmpty(&backStack)) {
                printf("No previous pages.\n");
            } else {
                push(&forwardStack, current);
                strcpy(current, pop(&backStack));
            }
        }

        // NEXT operation
        else if (strcmp(input, "NEXT") == 0) {
            if (isEmpty(&forwardStack)) {
                printf("No further pages.\n");
            } else {
                push(&backStack, current);
                strcpy(current, pop(&forwardStack));
            }
        }

        // PRINT HISTORY
        else if (strcmp(input, "PRINT HISTORY") == 0) {
            printf("\n--- BROWSER HISTORY ---\n");

            printStack(&backStack);

            if (strlen(current) != 0) {
                printf("%s\n", current);
            }

            // Forward stack printed in reverse order
            for (int i = forwardStack.top; i >= 0; i--) {
                printf("%s\n", forwardStack.data[i]);
            }

            printf("------------------------\n");
        }

        // URL visit
        else {
            // Basic validation (optional)
            if (strncmp(input, "https://", 8) == 0) {
                if (strlen(current) != 0) {
                    push(&backStack, current);
                }
                strcpy(current, input);
                clear(&forwardStack);
            } else {
                printf("Invalid input. Enter a valid URL or command.\n");
            }
        }
    }

    return 0;
}