#include <stdio.h>

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

int main() {
    // Constant folding example
    int result1 = constantFolding(2 * 3 + 4, 5 - 2, '+');
    printf("Result of 2 * 3 + 4 + 5 - 2 is: %d\n", result1);

    int result2 = constantFolding(10 / 2 * 3, 5, '*');
    printf("Result of 10 / 2 * 3 * 5 is: %d\n", result2);

    // Strength reduction example
    int result3 = strengthReduction(2 + 3);
    printf("Result of (2 + 3) << 1 is: %d\n", result3);

    int result4 = strengthReduction(4 * 5);
    printf("Result of (4 * 5) << 1 is: %d\n", result4);

    // Algebraic transformation example
    int result5 = algebraicTransformation(2 * 3 + 4, 5 - 2);
    printf("Result of (2 * 3 + 4 + 5 - 2) * (2 * 3 + 4 + 5 - 2) is: %d\n", result5);

    int result6 = algebraicTransformation(10 / 2 * 3, 5);
    printf("Result of (10 / 2 * 3 * 5) * (10 / 2 * 3 * 5) is: %d\n", result6);

    return 0;
}
