#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int pow;
    struct node *next;
};

void main () {
    int degree;
    printf("Enter the highest degree of polynomial: ");
    scanf("%d", &degree);

    struct node *head1 = malloc(sizeof(struct node)), *head2 = malloc(sizeof(struct node));
    head1->coeff = -1;
    head1->pow = degree + 1;
    head1->next = '\0';
    head2->coeff = -1;
    head2->pow = degree + 1;
    head2->next = '\0';
    
    struct node *temp1, *temp2;

    printf("\nEnter polynomial 1\n");
    for (int i = degree; i >= 0; i--) {
        struct node *new = malloc(sizeof(struct node));
        printf("x^%d: ", i);
        scanf("%d", &new->coeff);
        new->pow = i;
        new->next = '\0';

        temp1 = head1;
        
        while (temp1->next != '\0') {
            temp1 = temp1->next;
        }
        temp1->next = new;
    }

    printf("\nEnter polynomial 2\n");
    for (int i = degree; i >= 0; i--) {
        struct node *new = malloc(sizeof(struct node));
        printf("x^%d: ", i);
        scanf("%d", &new->coeff);
        new->pow = i;
        new->next = '\0';

        temp2 = head2;
        
        while (temp2->next != '\0') {
            temp2 = temp2->next;
        }
        temp2->next = new;
    }

    struct node *head3 = malloc(sizeof(struct node));
    head3->coeff = head1->next->coeff + head2->next->coeff;
    head3->pow = head1->next->pow;
    head3->next = '\0';    
    temp1 = head1->next->next; temp2 = head2->next->next;
    struct node *temp3 = head3;
    while (temp1 != '\0' && temp2 != '\0') {
        struct node *new = malloc(sizeof(struct node));
        new->coeff = temp1->coeff + temp2->coeff;
        new->pow = temp1->pow;
        new->next = '\0';

        temp3 = head3;
        while (temp3->next != '\0') {
            temp3 = temp3->next;
        }
        temp3->next = new;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp3 = head3;
    printf("\n");
    while (temp3 != '\0') {
        printf("%dx^%d + ", temp3->coeff, temp3->pow);
        temp3 = temp3->next;
    }
}