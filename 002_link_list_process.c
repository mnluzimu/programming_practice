#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find( List L, ElementType X ){
    List p = L;
    while(p){
        if(p->Data == X)
            return p;
        p = p->Next;
    }
    return ERROR;
}
List Insert( List L, ElementType X, Position P ){
    List p = L;
    List q = L;
    while(p){
        if(p == P)
            break;
        q = p;
        p = p->Next;
    }
    if(p){
        if(p == L){
            List t = (List)malloc(sizeof(struct LNode));
            t->Data = X;
            t->Next = p;
            L = t;
        }
        else{
            List t = (List)malloc(sizeof(struct LNode));
            t->Data = X;
            t->Next = p;
            q->Next = t;
        }
    }
    else if(L == NULL && P == NULL){
        List t = (List)malloc(sizeof(struct LNode));
        t->Data = X;
        t->Next = NULL;
        L = t;
    }
    else{
        printf("Wrong Position for Insertion");
        return ERROR;
    }
    return L;
}
List Delete( List L, Position P ){
    List p, q;
    p = q = L;
    while(p){
        if(p == P)
            break;
        q = p;
        p = p->Next;
    }
    if(p){
        if(p == L){
            L = p->Next;
            free(p);
        }
        else{
            q->Next = p->Next;
            free(p);
        }
        return L;
    }
    else{
        printf("Wrong Position for Deletion");
        return ERROR;
    }
}

