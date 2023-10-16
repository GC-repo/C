#include<stdio.h>
#include<stdlib.h>

struct node{
    int emp_id;
    char emp_name;
    int age;
    struct node* link;
};
void insertbeg(struct node** head)
{
    struct node* new1 = (struct node*)malloc(sizeof(struct node));
    printf("Enter employee ID: ");
    scanf("%d",&(new1->emp_id));
    printf("Enter employee NAME: ");
    scanf(" %c",&(new1->emp_name));
    printf("Enter Age: ");
    scanf("%d",&(new1->age));
    new1->link=*head;
    *head=new1;
    printf("The new node is added at beginning sucessfully\n\n");
}

void insertend(struct node* head)
{
    struct node* new1 = (struct node*)malloc(sizeof(struct node));
    new1->link = NULL;
    printf("Enter employee ID: ");
    scanf("%d",&(new1->emp_id));
    printf("Enter employee NAME: ");
    scanf(" %c",&(new1->emp_name));
    printf("Enter Age: ");
    scanf("%d",&(new1->age));
    struct node* temp;
    temp = head;
    while(temp->link!=NULL)
    {
        temp = temp->link;
    }
    temp->link = new1;
    printf("The new node is added at the end sucessfully\n\n");
}
void insertany(struct node** head)
{
    struct node* temp;
    temp = *head;
    int match;
    printf("Enter a employee ID from the list below\n");
    do{
        printf("|%d|",temp->emp_id);
        temp=temp->link;
    }while(temp->link!=NULL);
    printf("|%d|",temp->emp_id);
    printf("Enter specific employee id: ");
    scanf("%d",&match);
    temp=*head;
    int i=1;
    while(i>0)
    {
        if(temp->emp_id!=match)
        temp = temp->link;
        else
        i=0;
    }
struct node* new1 = (struct node*)malloc(sizeof(struct node));
    if(temp->link==NULL){
        new1->link= NULL;
    printf("Enter employee ID: ");
    scanf("%d",&(new1->emp_id));
    printf("Enter employee NAME: ");
    scanf(" %c",&(new1->emp_name));
    printf("Enter Age: ");
    scanf("%d",&(new1->age));
    struct node* temp1;
    temp1 = *head;
    while(temp1->link!=NULL)
    {
        temp1 = temp1->link;
    }
    temp1->link = new1;
}
else{
    printf("Enter employee ID: ");
    scanf("%d",&(new1->emp_id));
    printf("Enter employee NAME: ");
    scanf(" %c",&(new1->emp_name));
    printf("Enter Age: ");
    scanf("%d",&(new1->age));
    
    struct node* temp2;
    temp2 = temp->link;
    temp->link = new1;
    new1->link = temp2;
}
printf("The node is inserted after employee ID %d position sucessfully\n\n",match);
}

void display(struct node* head){
     struct node* temp = (struct node*)malloc(sizeof(struct node));
     temp=head;
     while(temp!=NULL)
     {
         printf("|Employee ID : %d|Employee Name : %c|Employee Age: %d|\n",temp->emp_id,temp->emp_name,temp->age);
         temp=temp->link;
     }
     while(temp=NULL){
     printf("|Employee ID : %d|Employee Name : %c|Employee Age: %d|\n\n",temp->emp_id,temp->emp_name,temp->age);
}}

void delete1(struct node** head)
{
    struct node* read;
    read = *head;
    printf("Enter an employee ID that are listed below\n");
    while(read->link !=NULL)
    {
        printf("|%d|",read->emp_id);
        read = read->link;
    }
    printf("|%d|\n",read->emp_id);
    int choice;
    scanf("%d",&choice);
    struct node* temp;
    temp = *head;struct node* prev;
    if(temp != NULL&& temp->emp_id ==choice){
        *head = temp->link;
        printf("The element with employee id %d has been deleted successfully\n\n",choice);
    }
    while(temp!=NULL && temp->emp_id!= choice)
    {
        prev=temp;
        temp = temp->link;
    }
    if(temp!=NULL)
    {
        prev->link = temp->link;
        printf("The element with employee id %d has been deleted successfully\n\n",choice);
    }
    else{
        prev->link = NULL;
        printf("The element with employee id %d has been deleted successfully\n\n",choice);
    }
}

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->emp_id = 1001;
    head->emp_name ='B';
    head->age = 27;
    head->link = NULL;
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current->link = NULL;
    head->link = current;
    current->emp_id = 1003;
    current->emp_name = 'D';
    current->age= 20;
    current = (struct node*)malloc(sizeof(struct node));
    current->link = NULL;
    head->link->link = current;
    current->emp_id = 1004;
    current->emp_name = 'E';
    current->age = 25;
    int choice;
    while(1)
    {
        printf("linked list menu\n");
        printf("1. insert a new record at the beginning of the list\n");
        printf("2. insert a new record at the end of the list\n");
        printf("3. insert a new record next to the record with a specific employee ID\n");
        printf("4. Delete the employee record for a specific employee ID\n");
        printf("5. Display the employee records\n");
        printf("6. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
               { insertbeg(&head);
                break;
               }
            case 2:{
                insertend(head);
                break;
            }
            case 3:{
                insertany(&head);
                break;
            }
            case 4:{
                delete1(&head);
                break;
            }
            case 5:{
                display(head);
                break;
            }
            case 6:{
                printf("Exiting program\n");
                struct node*temp;
                temp=head;
                while(temp->link!=NULL)
                {
                    free(temp);
                    temp = temp->link;
                }
                return 0;
            }
            default:{
                printf("Enter valid option");
            }
            
        }
    }
    return 0;
}
