# Balanced Parenthesis - complete discussion

Balence Parenthesis means each opening symbol has the corresponding closing symbol and the pairs of parenthesis are properly nested.

## Problem Statement
we are given an mathematical expression as a string and check whether the parenthesis in the particular expression is balanced or unbalanced.

The Balance Parenthesis comes under the application of stack, and can easily be implemented using stack

the problem can be implemented for single parenthesis as well for multiple parenthesis as per the given problem statement.

```
Example: (()) -> balanced(single type parentehsis)
{[()]} -> Balanced Multiple Parenthesis
{(]} -> UnBalanced
```

this is only simple parenthesis but under this we will also encounter the mathematical expression in problem statement, which while solving we have to ignore and only check for the type of parenthesis and its balanced conditions.

### Steps to solve the problem using stack
1. Create an empty stack of type char.
2. start iterating stack from beginning and check for the presence of parenthesis.
3. if opening bracket is formed, push element into the stack
4. if closing is found, check the top char in stack, if both are same then, simply pop element from stack.

### Condition for Balance parenthesis
- After completing all the iteration, if stack is empty then the particular expression has balanced parenthesis.

## Implementation 🔰
the implementation is straightforward as.

```c
int MatchParenthesis(char *exp) {
    //create and initialize stack
    struct stack *sp;
    sp->size = 70;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char *));
    char popped_ch;

    for(int i=0; exp[i]!='\0'; i++) {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{') {
            Push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}') {
            if(isEmpty(sp))
                return 0;
            popped_ch = Pop(sp);
            if(!match(popped_ch, exp[i])) {
                return 0;
            }
        }
    }
    if(isEmpty(sp)) {
        printf("Balanced Exp");
    }
    else {
        printf("Unbalanced Exp");
    }
}

```
## Best Case complexity:
At the start of iteration only if we encounter the closing bracket then expression could be concluded as unbalanced.
so it can be given as O(1) or constant

## Worst Case complexity:
If we have to iterate complete expression to conclude the result.
so, it can be expressed as O(N)


<h3 align="center"> Contributed by <a href="https://github.com/Raghavagr">Raghav Agrawal</a> With ❤️.</h3>