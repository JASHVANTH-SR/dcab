#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100

int constantFolding(int a, int b, char op) {
    int result;
    switch(op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            printf("Invalid operator");
            result = 0;
            break;
    }
    return result;
}

int strengthReduction(int x) {
    return x << 1;
}

int algebraicTransformation(int a, int b) {
    return (a + b) * (a + b);
}

int evaluateExpression(char *expr) {
    int result = 0;
    int num1 = 0, num2 = 0;
    char op = '\0';
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            if (num1 == 0) {
                num1 = atoi(token);
            } else {
                num2 = atoi(token);
                result = constantFolding(num1, num2, op);
                num1 = result;
            }
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            op = token[0];
        }
        token = strtok(NULL, " ");
    }
    return result;
}

int main() {
    char expr[MAX_EXPR_LENGTH];
    printf("Enter an expression to evaluate: ");
    fgets(expr, MAX_EXPR_LENGTH, stdin);
    expr[strcspn(expr, "\n")] = '\0';
    int result = evaluateExpression(expr);
    printf("Result: %d\n", result);
    return 0;
}
