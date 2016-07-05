#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int s[],int item, int *top){
    
    if(*top == 100){
        printf("stack is full\n");
        return ;
    }   
    
    (*top)++;
    s[*top] = item;

}

int pop(int s[], int *top){
    int item;
    if(*top == 0){
        printf("stack is empty\n");
        return 0 ;
    }
    
    item = s[*top];
    s[*top] = 0;
    (*top)--;
    return item;
}

// this is the program that simulates stack by array 
int main(){
    int stack[100];
    int top = -1;
    int input;
    int item;
    int i;
    while(1){
        printf("1 : push \n2 : pop  \n3  : print\n4 : end  \n input:");
        scanf("%d",&input);
        switch(input){
            case 1 :
                printf("input item : ");
                scanf("%d",&item);
                push(stack,item,&top);
                break;
            case 2 :
                item = pop(stack,&top);
                printf("pop : %d\n",item);
                break;
            case 3 : 
                for( i = 0; i<=top ;i++){
                    printf("%d\n",stack[i]);
                }
                break;
            case 4 :
                return 0;
            default:
                break;
        }
    }
}

