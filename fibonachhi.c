#include <stdio.h>

#define MAX_SIZE 100

int fibonacci(int k) {
    int stack[MAX_SIZE];  // Declare a stack to store intermediate Fibonacci numbers
    int top = -1;  // Initialize the stack top

    stack[++top] = 0;  // Push the first Fibonacci number (0) onto the stack
    stack[++top] = 1;  // Push the second Fibonacci number (1) onto the stack

    for (int i = 2; i <= k; i++) {
        int a = stack[top--];  // Pop the top element from the stack (a)
        int b = stack[top];    // Get the top element from the stack (b)

        stack[++top] = a;      // Push a back onto the stack
        stack[++top] = a + b;  // Push the sum of a and b onto the stack
    }

    return stack[top];
}

int main() {
    // Testing the function
    printf("%d\n", fibonacci(10));  // Output: 8

    return 0;
}