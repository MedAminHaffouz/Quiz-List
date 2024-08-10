#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
    char text[256];
    char choice1[256];
    char choice2[256];
    char choice3[256];
    int right_answer;
} question;

typedef struct node {
    question* Q;
    struct node* yes;
    struct node* no;
} node;

typedef node* list;

list push_question(list L) {
    list N = (list)malloc(sizeof(node));
    N->Q = (question*)malloc(sizeof(question));

    int x = -1;
    while (x != 1) {
        printf("Give the question: ");
        fgets(N->Q->text, sizeof(N->Q->text), stdin);
        N->Q->text[strcspn(N->Q->text, "\n")] = '\0';

        printf("Give item1: ");
        fgets(N->Q->choice1, sizeof(N->Q->choice1), stdin);
        N->Q->choice1[strcspn(N->Q->choice1, "\n")] = '\0';
        strcat(N->Q->choice1, "1.");

        printf("Give item2: ");
        fgets(N->Q->choice2, sizeof(N->Q->choice2), stdin);
        N->Q->choice2[strcspn(N->Q->choice2, "\n")] = '\0';
        strcat(N->Q->choice2, "2.");

        printf("Give item3: ");
        fgets(N->Q->choice3, sizeof(N->Q->choice3), stdin);
        N->Q->choice3[strcspn(N->Q->choice3, "\n")] = '\0';
        strcat(N->Q->choice3, "3.");

        printf("Give the right answer's number: ");
        scanf("%d", &(N->Q->right_answer));
        getchar();  // Clear the newline character from the input buffer

        while (x != 0 && x != 1) {
            puts(N->Q->text);
            puts(N->Q->choice1);
            puts(N->Q->choice2);
            puts(N->Q->choice3);
            printf("Right answer: %d\nConfirm? (0/1): ", N->Q->right_answer);
            scanf("%d", &x);
            getchar();  // Clear the newline character from the input buffer
        }
    }

    if (L == NULL) {
        N->yes = NULL;
        L = N;
        N->no = L;
        return L;
    } else {
        list p = L;
        while (p->yes != NULL) {
            p = p->yes;
        }
        p->yes = N;
        N->no = L;
        return L;
    }
}

void showlist(list L) {

}

int main(void) {
    printf("Hello, World!\n");
    list L = NULL;
    L = push_question(L);
    L = push_question(L);
    L = push_question(L);
    return 0;
}

