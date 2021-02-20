#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr) {
    if(ptr->top == -1) {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if(ptr->top == ptr->size -1) {
        return 1;
    }
    else{
        return 0;
    }
}

void Push(struct stack *ptr, char val) {
    if(isFull(ptr)) {
        printf("\nStack overflow!.. cannot insert");
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char Pop(struct stack *ptr) {
    char val;
    if(isEmpty(ptr)) {
        printf("\nStack undererflow!.. cannot popped");
    }
    else {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b) {
    if(a=='(' && b==')' || a=='[' && b==']' || a=='{' && b=='}') {
        return 1;
    }
    else {
        return 0;
    }
}

int ParenthesisMatch(char *exp) {
    // create and initialize the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char *));
    char popped_ch;
    
    for(int i=0; exp[i] != '\0'; i++) {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[') {
            Push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']') {
            if(isEmpty(sp)) {
                return 0;
            }
            popped_ch = Pop(sp);
            if(!match(popped_ch, exp[i])) {
                return 0;
            }
        }
    }
    
    if(isEmpty(sp)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
	char * exp = "{[(4-6)+7]*2}";
	if(ParenthesisMatch(exp)) {
	    printf("\nParenthesis is balanced");
	}
	else {
	    printf("\nParenthesis is not balanced");
	}
	return 0;
}