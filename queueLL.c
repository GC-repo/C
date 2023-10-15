#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

void enqueue(struct Queue* q,char val)
   {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
   }
   
   char dequeue(struct Queue* q)
   {
       if (q->front == NULL)
       {
           printf("Queue is empty. Cannot dequeue. \n");
           return '\0';
       }
       struct Node* temp = q->front;
       char data = temp->data;
       
       q->front = q->front->next;
       if(q->front == NULL)
       {
           q->rear = NULL;
       }
       free(temp);
       return data;
   }
   int main()
   {
       char q[] = "EAS*Y*QUE***ST***IO*N***";
       struct Queue queue;
       queue.front = NULL;
       queue.rear = NULL;
       
       for(int i=0;i<= strlen(q);i++)
       {
       if(q[i]=='*')
       {
           char popped = dequeue(&queue);
           if (popped != '\0')
           {
               printf("%c", popped);
           }
       }else{
           enqueue(&queue,q[i]);
       }
   }
   }
