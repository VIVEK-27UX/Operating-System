#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Provides access to POSIX operating system API (fork, getpid, getppid)

int main() {
    // Duplicate the calling process to create a child process
    pid_t pid = fork();

    // Check if the fork system call failed
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE); // Terminate execution on failure
    }
    // Execution path for the Child Process (fork() returns 0 to the child)
    else if (pid == 0) {
        printf("--- Child Process ---\n");
        printf("Child PID  : %d\n", getpid());  // Current process ID
        printf("Parent PID : %d\n\n", getppid()); // ID of the parent process
    } 
    // Execution path for the Parent Process (fork() returns Child's PID to parent)
    else {
        printf("--- Parent Process ---\n");
        printf("Parent PID : %d\n", getpid()); // Current process ID
        printf("Child PID  : %d\n\n", pid);   // PID returned by fork()
    }

    return 0;
}
