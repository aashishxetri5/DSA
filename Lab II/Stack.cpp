#include <iostream>
#include <stdlib.h>

#define size 100

int stack[size];
int top = 0, flag = 0;

void push(int item){
    if(top == size){
        std::cout << "\nStack is full!!\n\n";
    } else {
        stack[top++] = item;
        std::cout << item << " pushed into the stack. \n\n";
    }
}

int pop() {
    if(top == 0) {
        std::cout << "Stack is empty";
    } else {
        int item;
        item = stack[--top];
        std::cout << "\nPopped:";
    return item;
    }
    flag = 1; // This prevents from displaying 0 when stack is empty and pop is called.
    return NULL;
}

void display(){
    if(top == 0) {
        std::cout << "Nothing to Display\n";
    } else {
        for(int i = 0; i < top; i++) {
            std::cout << *(stack+i) << " ";
        }
    }
}

int main() {

    int choice, num, popped_val;

    while(true) {
        std::cout << "Press 1 to Push\n";
        std::cout << "Press 2 to Pop\n";
        std::cout << "Press 3 to Display\n";
        std::cout << "Press 0 to Exit\n";

        std::cin >> choice;
        switch(choice) {
            case 1:
                std::cout << "Enter the number to push: ";
                std::cin >> num;
                push(num);
                break;
            case 2:
                popped_val = pop();
                if(!flag){
                    std::cout << popped_val;
                    flag = 0;
                }

                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Displaying items on the stack\n";
                display();
                std::cout << std::endl;
                break;
            case 0:
                std::cout << "Exiting...\n";
                exit(0);
                break;
            default:
                std::cout << "Invalid Input!!";
                break;
        }
    }

    return 0;
}