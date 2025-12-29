#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop operation
char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

// Function to check matching brackets
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balanced parentheses
int isBalanced(char expr[]) {
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                return 0; // No matching opening bracket
            }
            char open = pop();
            if (!isMatchingPair(open, ch)) {
                return 0;
            }
        }
    }

    // If stack is empty, expression is balanced
    return (top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isBalanced(expr))
        printf("Expression is Balanced\n");
    else
        printf("Expression is NOT Balanced\n");

    return 0;
}
