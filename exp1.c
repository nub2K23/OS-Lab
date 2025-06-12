#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid, ret, status;
    pid = fork();

    if (pid == 0) {
        // In child process
        char *args[] = {"./parent", NULL};  // Replace "./parent" with your actual executable
        execvp(args[0], args);
        // If execvp fails:
        perror("execvp failed");
    } else if (pid > 0) {
        // In parent process
        ret = waitpid(pid, &status, 0);
        printf("\nI am in parent\n");

        if (ret == -1) {
            perror("waitpid error");
        } else if (ret == pid) {
            printf("I am waiting in parent\n");
        } else {
            printf("Unexpected waitpid result\n");
        }
    } else {
        // Fork failed
        perror("fork failed");
    }

    return 0;
}
