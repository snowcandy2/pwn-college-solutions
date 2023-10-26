#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pwncollege() {
    printf("This is the pwncollege function.\n");
}

int main() {
    pwncollege();

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        execl("/challenge/embryoio_level32", "/challenge/embryoio_level32", NULL);
        perror("Exec failed");
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
