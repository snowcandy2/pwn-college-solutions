#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pwncollege() {
    printf("You got it!\n");
}

int main() {
    pwncollege();
    pid_t pid = fork();
    if (pid == 0) { // First child process
        chdir("/tmp");
        
        pid_t second_pid = fork();
        if (second_pid == 0) { // Second child process
            chdir("/tmp/uejsun");
            char *argv[] = {"/challenge/embryoio_level85", NULL};
            execvp(argv[0], argv);
        } else if (second_pid > 0) {
            wait(NULL);
        }
        
    } else if (pid > 0) { // Parent process
        wait(NULL);
    }
    return 0;
}
