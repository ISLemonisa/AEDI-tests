#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Stack Stack;

struct Stack{
    double data;
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
    Stack *topo = malloc(sizeof(Stack));
    topo == NULL;
}

void Push(Stack *S, double X)
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
    printf("%lf\n", S->next->data);
    printStack(S->next);
    
}

void LerStack(Stack *S)
{
    int i = 1;
    double num;
    while( i< 5){
        printf("Insira o elemento %d da pilha:\n", i);
        scanf("%lf", &num);
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
  Stack *S = CreateStack();
  LerStack(S);
  printStack(S);
  S->next = S->next->next;
  DeleteStack(S);
  printStack(S);
}







