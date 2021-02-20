#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr) {
    if(ptr->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if(ptr->top == ptr->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void Push(struct stack *ptr, char val) {
    if(isFull(ptr)) {
        printf("\nStack Overflow!. cannot push %c in the stack",val);
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char Pop(struct stack *ptr) {
    if(isEmpty(ptr)) {
        printf("\nStack Underflow!.. cannot pop from stack");
    }
    else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
} 

int parenthesisMatch(char * xpp) {
    // create and initialize the stack
    struct stack *sp;
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char *));
    
    for(int i=0; xpp[i] != '\0'; i++) {
        if(xpp[i] == '(') {
            Push(sp, '(');
        }
        else if(xpp[i] == ')') {
            if(isEmpty(sp)) {
                return 0;
            }
            Pop(sp);
        }
    }
    
    if(isEmpty(sp)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    char * xpp = "((8)(*--$$9))";
    // Check if stack is empty
    if(parenthesisMatch(xpp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}