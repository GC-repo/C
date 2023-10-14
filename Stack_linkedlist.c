#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Linkedliststack
{
    struct Node* head;
};

struct Node* createNode(char data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    
}
struct Linkedliststack* createStack(){
    struct Linkedliststack* stack = (struct Linkedliststack*)malloc(sizeof(struct Linkedliststack));
    stack->head = NULL;
    return stack;
}

int isEmpty(struct Linkedliststack* stack){
    return (stack->head == NULL);
}

void push(struct Linkedliststack* stack,char data){
    struct Node* newNode = createNode(data);
    newNode->next = stack->head;
    stack->head = newNode;
}

char pop(struct Linkedliststack* stack)
{
    if(isEmpty(stack)){
        printf("Stack underflow!\n");
        return '\0';
    }
    struct Node* temp = stack->head;
    char poppedData = temp->data;
    stack->head = temp->next;
    free(temp);
    return poppedData;
}
int isBalanced(char* expression)
{
    struct Linkedliststack* stack = createStack();
    

for (int i=0; expression[i] != '\0' ;i++)
{
    if (expression[i] == '(')
    {
        push(stack, expression[i]);
    }
    else if (expression[i]== ')')
    {
    if (isEmpty(stack))
    {
        return 0;
    }
    pop(stack);
}
}
return isEmpty(stack) ? 1 : 0 ;
}

int main()
{
    char expression[100];
    
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    for(int i=0; expression[i] != '\0';i++)
    {
        if (expression[i] == '\n')
        {
            expression[i] = '\0';
            break;
        }
    }
    printf("%s is %s balanced.\n",expression, isBalanced(expression) ? "" : "not");
    return 0;
}
