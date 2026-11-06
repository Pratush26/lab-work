#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};
int main() {
    int num;
    printf("Enter a value to add in linked list: ");
    scanf("%d", &num);
    struct node *head = malloc(sizeof(struct node));
    head->data=num;
    head->link=NULL;
    printf("data %d; next %d", head->data, head->link ? head->link->data : 0);
    return 0;
}