#include <stdio.h>
#include <stdlib.h>


typedef struct AvlTree AvlTree;

struct AvlTree{
    int data;
    AvlTree *right;
    AvlTree *left;
    int altura;
};

int Altura(AvlTree *A){
    if(A == NULL)
        return -1;
    else
        return A->altura;
}

int Max(int a, int b){
    if(a>= b)
        return a;
    else
        return b;
}

AvlTree *Rot1Esquerda(AvlTree *K2){
    AvlTree *K1;
    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;
    K2->altura = Max(Altura(K2->left), Altura(K2->right)) + 1;
    K1->altura = Max(Altura(K1->left), K2->altura ) + 1;
    return K1;
}

AvlTree *Rot1Direita(AvlTree *K2){
    AvlTree *K1;
    K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;
    K2->altura = Max(Altura(K2->right), Altura(K2->left)) + 1;
    K1->altura = Max(Altura(K1->right), K2->altura ) + 1;
    return K1;
}


AvlTree *Rot2Esquerda(AvlTree * K3){
    K3->left = Rot1Direita(K3->left);
    return Rot1Esquerda(K3);
}


AvlTree *Rot2Direita(AvlTree * K3){
    K3->right = Rot1Esquerda(K3->right);
    return Rot1Direita(K3);
}


AvlTree *Insert(int num, AvlTree *A){
    if( A== NULL){
        A = malloc(sizeof(AvlTree));
        if(A ==  NULL){
            printf("ERRO!FALTA DE MEMORIA./n");
            exit(1);
        }
        else{

            A->data = num;
            A->altura = 0;
            A->left = A->right = NULL;
        }

    }
    else if(num < A->data){
        A->left = Insert(num, A->left);
        if( Altura(A->left) - Altura(A->right) == 2){
            if(num < A->left->data){
                A = Rot1Esquerda(A);

            }
            else
                A = Rot2Esquerda(A);
        }
    }
    else if( num > A->data){
        A->right = Insert(num, A->right);
        if(Altura(A->right) - Altura(A->left) == 2){
            if( num > A->right->data){
                A = Rot1Direita(A);
            }
            else
                A = Rot2Direita(A);
        }
    }
    A->altura = Max(Altura(A->left), Altura(A->right)) + 1;
    return A;
}


int main()
{
    int i = 0;
    int num, b;
    AvlTree *A;
    while(i < 8){
        scanf("%d", &num);
        A = Insert(num, A);
        i++;
    }
    b = Altura(A);
    printf("%d\n", b);
    return 0;
}
