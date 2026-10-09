#include <stdio.h>
#define LIMIT 10000

int arr[LIMIT], f = 0, e = 0, sz = 0;

void push(int val){
    if (e >= LIMIT) {
        printf("Queue is full!\n");
        return;
    }
    arr[e] = val;
    printf("Added %d\n", arr[e]);
    e++;
    sz++;
}

void pop(){
    if(sz <= 0){
        printf("The queue is empty!\n");
        return;
    }
    printf("Deleted %d\n", arr[f]);
    f++;
    sz--;
}
void front(){
    if(sz <= 0){
        printf("The queue is empty!\n");
        return;
    }
    printf("Front element: %d\n", arr[f]);
}

void display(){
    if(sz <= 0){
        printf("The queue is empty!\n");
        return;
    }
    for (int i = f; i < e; i++) printf("%d ", arr[i]);

    printf("\n");
}
int main() {
    printf("Instruction Set:\n");
    printf("Write: (instruction type) (value)\n");
    printf("A: add element\n");
    printf("D: delete element\n");
    printf("E: Exit\n");
    printf("F: front element\n");
    printf("T: traverse elements\n");
    printf("S: size of queue\n");
    char c;
    int val;
    while (1) {
        if (scanf(" %c", &c) != 1) break;

        if (c == 'E') break;

        if (c == 'A') {
            if (scanf("%d", &val) != 1) break;
            push(val);
        }
        else if (c == 'D') pop();
        else if (c == 'F') front();
        else if (c == 'S') printf("The size of the queue: %d\n", sz);
        else if (c == 'T') display();
        else printf("Invalid instruction!\n");
    }
    return 0;
}

// Sample input
// A 10
// A 20
// A 30
// F
// S
// T
// D
// F
// S
// T
// A 40
// T
// E