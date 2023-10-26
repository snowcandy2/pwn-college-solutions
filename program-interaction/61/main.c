#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pwncollege() {
    printf("Pass the check.");
}

int main() {
    pwncollege();
    int pipefd[2];
    pid_t pid1, pid2;

    // 创建一个管道
    pipe(pipefd);

    // 分叉第一个子进程
    pid1 = fork();
    if (pid1 == 0) {
        // 将 stdout 重定向到管道的写端
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        execvp("/challenge/embryoio_level61", (char * const []){"/challenge/embryoio_level61", NULL});
    }

    // 分叉第二个子进程
    pid2 = fork();
    if (pid2 == 0) {
        // 将 stdin 重定向到管道的读端
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        // execvp("grep pwn", (char * const []){"grep pwn", NULL});
        execvp("grep", (char * const []){"grep", "pwn", NULL});
    }

    // 在父进程中关闭管道的两端
    close(pipefd[0]);
    close(pipefd[1]);

    // 等待两个子进程完成
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}
