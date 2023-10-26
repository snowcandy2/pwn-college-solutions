#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void pwncollege() {
    printf("This function ensures I pass the challenge checks.\n");
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
        int fd = open("/tmp/brxhzr", O_RDONLY);
        if (fd < 0) {
            perror("File open failed");
            return 1;
        }
        dup2(fd, STDIN_FILENO);
        close(fd);

        execl("/challenge/embryoio_level33", "/challenge/embryoio_level33", NULL);
        perror("Exec failed");
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
