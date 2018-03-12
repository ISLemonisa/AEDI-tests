
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack{
    int data;
    Stack *next;
};

int IsEmpty(Stack *ptr)
{
    return ptr->next == NULL;
}

void Pop(Stack *S)
{
    Stack *first;
    first= S->next;
    S->next= S->next->next;
    free(first);
    
}

Stack *CreateStack(void)
{
    Stack *S = malloc(sizeof(struct Stack));
    if( S == NULL){
        printf("Sem espaco.");
    } else {
        while( !IsEmpty(S)){
            Pop(S);
        }
    }
    return S;
}

void Push(Stack *S, int X)
{
    Stack *tmp;
    tmp = malloc(sizeof(struct Stack));
    if( tmp == NULL){
        printf("Sem espaco.");
    }
    else{
        tmp->data = X;
        tmp->next = S->next;
        S->next = tmp;
    }
}

void printStack(Stack *S)
{
    if( S->next != NULL){
        printf("%d\n", S->data);
        printStack(S->next);
    }
}

void LerStack(Stack *S)
{
    int i = 1;
    int num;
    while( i< 5){
        printf("Insira o elemento %d da pilha:\n", i);
        scanf("%d", &num);
        Push(S, num);
        i++;
    }
}

void DeleteStack(Stack *S)
{
    Stack *tmp;
    while(!IsEmpty(S)){
        tmp->next = S->next;
        S->next = S->next->next;
        free(tmp);
    }
    
}

int main()
{
    Stack *S;
    S = CreateStack();
    LerStack(S);
    
    DeleteStack(S);
    return 0;
}