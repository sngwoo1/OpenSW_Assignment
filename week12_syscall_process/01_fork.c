#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == 0)
    {
        printf("Child process PID: %lu\n Child process ppid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
        exit(7);
    }
    else
    {
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            printf("Child exited with status code: %d\n", code); 
        }
        printf("parent process pid: %lu\n parent process  ppid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());

    }
    return 0;
}