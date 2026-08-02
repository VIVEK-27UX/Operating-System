#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;

    // Prompt user for input count
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input! Please enter a non-negative integer.\n");
        return 1;
    }

    // Duplicate process to create a child
    pid_t pid = fork();

    // Error handling if fork fails
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } 
    // Child Process: Generates and prints Fibonacci sequence up to n terms
    else if (pid == 0) {
        printf("\n[Child Process] First %d terms of Fibonacci series:\n", n);
        long long a = 0, b = 1, next;

        for (int i = 1; i <= n; i++) {
            printf("%lld ", a);
            next = a + b;
            a = b;
            b = next;
        }
        printf("\n");
    } 
    // Parent Process: Computes factorial of n
    else {
        long long fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }

        // Wait for child process to complete execution before printing and exiting
        wait(NULL);
        printf("\n[Parent Process] Factorial of %d = %lld\n", n, fact);
    }

    return 0;
}
