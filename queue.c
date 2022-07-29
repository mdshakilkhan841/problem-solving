//Queue Implementation Using Array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void enqueue(int);
void dequeue();
void display();

int queue[SIZE],  front=-1, rear=-1;

void enqueue(int value){
    if(rear == SIZE -1){
        printf("\nQueue is Full !!\n");
    }
    else{
        if(front == -1)
            front = 0;
        rear++;
        queue[rear]= value;
    }
} 

void dequeue(){
    if(front == -1)
        printf("Queue is Empty");
    else{
        front++;
        if(front>rear){
            front = rear = -1;
        }
    }
}

void display(){
    if(front == -1)
        printf("Queue is Empty");
    else{
        int i;
        printf("\nQueue Elements are:\n");
        for(i = front; i<=rear; i++){
            printf("%d\t", queue[i]);
        }
    }
}

void main(){
    int value, choice;
    while (1){
        printf("\n1. EnQueue\n2. DeQueue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("Enter the value to be insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
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