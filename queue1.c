#include <stdio.h>
#include <stdlib.h>

int a[10], front = -1, rear = -1, n;

void insert() {
    int x;
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &x);

        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else if (rear == n - 1 && front != 0) {
            rear = 0;
        } else {
            rear = (rear + 1) % n;
        }
        a[rear] = x;
    }
}

void display() {
    int i;
    printf("Front = %d, Rear = %d\n", front, rear);
    if (front == -1) {
        printf("Queue is empty\n");
    } else if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", a[i]);
        }
    } else {
        for (i = front; i < n; i++) {
            printf("%d ", a[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void del() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted element: %d\n", a[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            if (front == n - 1) {
                front = 0;
            } else {
                front = front + 1;
            }
        }
    }
}

void search() {
    int x, i, j;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    if (front <= rear) {
        int found = 0;
        for (i = front; i <= rear; i++) {
            if (a[i] == x) {
                printf("Element found at position: %d\n", i);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Element not found\n");
        }
    } else {
        int found = 0;
        for (i = front, j = 1; i < n; i++, j++) {
            if (a[i] == x) {
                printf("Element found at position: %d\n", j);
                found = 1;
                break;
            }
        }
        if (!found) {
            for (i = 0; i <= rear; i++) {
                if (a[i] == x) {
                    printf("Element found at position: %d\n", i + n);
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            printf("Element not found\n");
        }
    }
}

void main() {
    char ch;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    while (1) {
        printf("\n1. Insertion\n2. Deletion\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &ch);  // Notice the space before %c to catch any newline or space characters.

        switch (ch) {
            case '1': insert(); break;
            case '2': del(); break;
            case '3': search(); break;
            case '4': display(); break;
            case '5': 
                printf("\nExiting program...\n");
                exit(0);
                break;
            default: 
                printf("\nInvalid choice\n");
        }
    }
}

