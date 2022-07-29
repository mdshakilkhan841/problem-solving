#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE], front = -1, rear = -1;

void enQueue(int value)
{
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
        printf("\nCircular Queue is Full! Insertion not possible!!!\n");
    else{
        if(front == -1)
	        front = 0;
        rear = (rear + 1) % SIZE;
        cQueue[rear] = value;
        printf("\nInsertion Success!!!\n");
   }
}
void deQueue(){
    if(front == -1 && rear == -1)
        printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
    else{
        printf("\nDeleted element : %d\n",cQueue[front]);
        
        // incrementing the front value
        if (front == rear){
            front = rear = -1;
        } 
        else{
            front = (front + 1) % SIZE;
        }
    }
}

void display(){
    int i;
    if(front == -1)
        printf("\nCircular Queue is Empty!!!\n");
    else {
        printf("\nCircular Queue Elements are : \n");
        for (i = front; i != rear; i = (i+1)%SIZE ){
            printf("%d\t", cQueue[i]);
        }
//        printf("%d ", cQueue[i]);
    }
// -----***Altranate way of printing the value***--------
//     else{
//         int i = front;
//         printf("\nCircular Queue Elements are : \n");
//         if(front <= rear){
// 	        while(i <= rear)
// 	            printf("%d\t",cQueue[i]);
//                 i++;
//         }
//         else{
// 	        while(i <= SIZE-1)
// 	            printf("%d\t", cQueue[i++]);
// 	        i = 0;
// 	        while(i <= rear)
// 	        printf("%d\t",cQueue[i++]);
//       }
//    }
}

void main(){
   int choice, value;
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("\nEnter the value to be insert:  ");
		 scanf("%d",&value);
		 enQueue(value);
		 break;
	 case 2: deQueue();
		 break;
	 case 3: display();
		 break;
	 case 4: exit(0);
	 default: printf("\nPlease select the correct choice!!!\n");
      }
   }
}