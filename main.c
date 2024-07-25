#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
    char* text;
    char* choice1;
    char* choice2;
    char* choice3;
    int right_answer;
}question;

typedef struct node {
    question* Q;
    struct node* yes;
    struct node* no;
}node;

typedef node* list;

list push_question(list L) {
    list N=(list)malloc(sizeof(node));
    N->Q=(question*)malloc(sizeof(question));
    int x=-1;
    while (x!=1) {
        printf("Give the question");
        gets(N->Q->text);
        printf("Give item1 : ");
        gets(N->Q->choice1);
        strcat("1.",N->Q->choice1);
        printf("Give item2 : ");
        gets(N->Q->choice2);
        strcat("2.",N->Q->choice2);
        printf("Give item3 : ");
        gets(N->Q->choice3);
        strcat("3.",N->Q->choice3);
        printf("Give the right answer's number : ");
        scanf("%d",&(N->Q->right_answer));
        while ((x!=0)||(x!=1)) {
            puts(N->Q->text);
            puts(N->Q->choice1);
            puts(N->Q->choice2);
            puts(N->Q->choice3);
            printf("Right answer : %d\n Confirm ? (0/1)",N->Q->right_answer);
            scanf("%d",&x);
        }
    }
    if (L==NULL) {
        N->yes=NULL;
        L=N;
        N->no=L;
        return L;
    }
    else {
        list p=L;
        while (p->yes!=NULL) {
            p=p->yes;
        }
        p->yes=N;
        N->no=L;
        return L;
    }
}

int main(void) {
    printf("Hello, World!\n");
    list L=NULL;
    L=push_question(L);
    return 0;
}
