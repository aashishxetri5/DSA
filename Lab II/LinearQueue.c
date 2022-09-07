#include <stdio.h>
#include <stdlib.h>

#define size 5

int Queue[size];
int front = 0, rear = -1;

void enqueue(int item){
    if(rear == size-1) {
        printf("\nQueue is Full!!\n\n");
    } else {
        Queue[++rear] = item;
        printf("\n%d added to the Queue!\n\n", item);
    }
}

int dequeue() {
    if(front > rear) {
        printf("\nQueue is empty!!\n");
    } else {
        int item = Queue[front++];
        return item;
    }
    return NULL;
}

void display() {
    if(rear == -1 || front == size){
        printf("\nThe Queue is empty!!\n");
    }else{
        int i;
        printf("Displaying items on the queue\n");
        for(i = front; i <= rear; i++) {
            printf("%d ", Queue[i]);
        }
    }
}


int main(){
    int choice, num;

    while(1) {
        printf("Press 1 to Enqueue\n");
        printf("Press 2 to Dequeue\n");
        printf("Press 3 to Display\n");
        printf("Press 0 to Exit\n");

        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the number to Enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                printf("\nDequeued: %d\n", dequeue());
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