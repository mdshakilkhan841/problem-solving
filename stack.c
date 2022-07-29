//Stack Implementation
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 10

void push(int);
void pop();
void display();
int stack[SIZE], top= -1 ;


void push(int value){
    if(top == SIZE-1){
        printf("Stack is Full/ Overflow !!");
    }
    else{
        top++;
        stack[top] = value;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is Empty/ Underflow !!");
    }
    else{
        stack[top];
        top--;
    }
}

void display(){
    if(top == -1){
        printf("Stack is Empty/Underflow !!");
    }
    else{
        int i;
        printf("\nStack Elements are:\n");
        for(i=top; i>=0; i--){
            printf("\t%d\n", stack[i]);
        }
    }
}


void main(){
    int value, choice;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Enter the value to be insert: ");
                scanf("%d", &value);
                push(value);

                break;
            case 2:
                pop();
                printf("\nDeleted : %d", stack[top]);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n---Wrong Selection !!--- Try Again !!\n");
        }
    }
}