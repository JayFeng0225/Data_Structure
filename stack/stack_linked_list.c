#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}list;
//typedef struct node stack;

list *top = NULL;
void push(int item){
    list *insert = (list *)  malloc (sizeof(list));
    insert->data = item;
    insert->next = top;
    top = insert;
}

int pop(){
    int item;
    list *ptr = top;
    item = top->data;
    top = top->next;
    free(ptr);
    return item;
}

int main(){
    int i;
    int input;
    int item = -1;
    list *ptr;
    while(1){
    printf("1: push 2:pop 3:print 4:end\n");
    scanf("%d",&input);
    switch(input){
        case 1:
            printf("input:");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item = pop();
            printf("pop:%d\n",item);
            break;
        case 3:
            ptr = top;
            while(ptr != NULL){
                printf("%d\n",ptr->data);
                ptr = ptr->next;
            }     
            break;
        case 4:
            return;
        default:
            break;
    }
    }
}
