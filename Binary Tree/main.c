#include <stdio.h>
#include <stdlib.h>

typedef struct ArvBin ArvBin;
typedef struct PtrNode PtrNode;

struct ArvBin{
    int data;
    ArvBin *right;
    ArvBin *left;
};

ArvBin *MakeEmpty( ArvBin *A)
{
    if(A != NULL){
        MakeEmpty(A->right);
        MakeEmpty(A->left);
        free(A);
    }
    return NULL;
}

ArvBin *FindP(int X, ArvBin *A)
{
    if( A != NULL){
        if(X == A->data){
            printf("Dado encontrado.");
            return A;
        } else{
            if( X < A->data){
                return FindP(X, A->left);
            } else 
                return FindP(X, A->right);
        }
    } else{
        printf("Dado nao foi encontrado");
        return NULL;
    }
}

ArvBin *Insert( ArvBin *A, int X){
    if( A == NULL){
        A = malloc(sizeof(ArvBin));
        if(A == NULL){
            printf("Sem espaco!\n");
            return NULL;
        }
        else{
            A->data = X;
            A->left = A->right = NULL;
        }
    }
    else if(X < A->data){
        A->left = Insert(A->left, X);
    }
    else if(X > A->data){
        A->right = Insert(A->right, X);
    }
    return A;
}

ArvBin *FindMax(ArvBin *A){
    if( A != NULL){
        while(A->right != NULL)
            A = A->right;
    }
    return A;    
}

ArvBin *FindMin(ArvBin *A){
    if( A != NULL){
        while(A->left != NULL)
            A = A->left;
    }
    return A;   
}


ArvBin *Delete(ArvBin *A, int X){
    ArvBin *tmp;
    if( A == NULL){
        printf("Erro\n");
        return NULL;
    }
    else if(X < A->data){
        A->left = Delete(A->left, X);
    }
    else if(X > A->data){
        A->right = Delete(A->right, X);
    }
    else if(A->left && A->right){ /*dois filhos*/
        tmp = FindMin(A->right);
        A->data = tmp->data;
        A->right = Delete( A->right, A->data);
    }
    else{
        tmp = A;
        if(A->left == NULL){
            A = A->right;
        }
        else if(A->right == NULL){
            A = A->left;
        }
        free(tmp);
    }
    return A;
    
}

ArvBin *getNum(int size, ArvBin *A){
    int a, i;
    i = 0;
    ArvBin *tmp;
    while(i < size){
        printf("Insira o número desejado\n");
        scanf("%d", &a);
        A = Insert(A, a);
        i++;
    }
    return A;
}

void printArv(ArvBin *A) {
	if(A == NULL)
		return;
	printf("%d\n",A->data);
	printArv(A->left);
	printArv(A->right);									
}

int main() {
    int size;
    ArvBin *A = malloc(sizeof(ArvBin));
    A = MakeEmpty(A);
    printf("Insira a quantidade de elementos:\n ");
    scanf("%d", &size);
    A = getNum(size, A);
    Delete(A, 44);
    ArvBin *S = FindMax(A);
    printf("max = %d\n", S->data);
    
    MakeEmpty(A);
    return 0;
}

