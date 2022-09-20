#include <stdio.h>
#include <stdlib.h>

#define size 4

int cir_queue[size];
int front = -1, rear = 0, flag = 0;

// Adds one element to the queue.
void enqueue(int item) {

    if (front == (rear + 1) % size) {
        printf("The queue is full!!\n");
    } else {
        if(front == -1) {
            front += 1;
        }
        cir_queue[rear] = item;
        rear = (rear + 1) % size;
        printf("\n%d added to the Queue!\n\n", item);
        
    }
}

// Removes the first element from the queue.
int dequeue() {
    
    if (front == -1 || front == rear) {
        printf("The queue is Empty!!\n");
    } else {
        int item = cir_queue[front];
        front = (front + 1) % size;
        
        return item;
    }
    flag = 1;
    return 0;
}

// Displays all the items currently in the queue.
void display() {
    
    if (front == -1 || front == rear) {
        printf("Nothing to display!!\n");
    } else {
        int i;
        printf("Displaying items on the queue:\n");
        if(rear >= front){
            
            for (i = front; i < rear; i++) {
                printf("%d ", cir_queue[i]);
            }
        } else {
            
            for(i = front; i < size; i++){
                printf("%d ", cir_queue[i]);
            }
            for(i = 0; i < rear; i++){
                printf("%d ", cir_queue[i]);
            }
        }
    }
}

int main() {

    int choice, num, item;

    printf("Press 1 to Enqueue\n");
    printf("Press 2 to Dequeue\n");
    printf("Press 3 to Display\n");
    printf("Press 0 to Exit\n");

    while(1) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the number to Enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                item = dequeue();
                if(!flag) {
                    printf("\nDequeued: %d\n", item);
                } else {
                    flag = 0;
                }
                break;
            case 3:
                display();
                printf("\n\n");
                break;
            case 0:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid Input!!");
                break;
        }
    }

    return 0;
}