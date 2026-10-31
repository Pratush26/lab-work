#include<stdio.h>
#define LIMIT 5

int arr[LIMIT], sz = 0;

void push(int n){
    if(sz >= LIMIT){
        printf("The Stack is full\n");
        return;
    }
    arr[sz] = n;
    sz++;
}
void pop(){
    if(sz <= 0){
        printf("The Stack is Empty\n");
        return;
    }
    sz--;
}
void show(){
    for(int i = sz-1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    printf("Operation List\n");
    printf("A value - Addtion\n");
    printf("D - Deletion\n");
    printf("S - Show\n");
    printf("E - Exit\n");
    int n;
    char op;
    while(1){
        scanf(" %c", &op);
        if(op == 'A'){
            scanf("%d", &n);
            push(n);
        }
        else if(op == 'D'){
            pop();
        }
        else if(op == 'S'){
            show();
        }
        else if(op == 'E'){
            break;
        }
        else{
            printf("Invalid Operation\n");
        }
    }
    return 0;
}