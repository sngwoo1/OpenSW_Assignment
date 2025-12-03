#include <sys/types.h>
//#include <sys/wait.h>
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
        sleep(1);
        printf("Child process PID: %lu\n Child process ppid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
        exit(7);
    }
    else
    {
        printf("parent process pid: %lu\n parent process  ppid: %lu\n", (unsigned long)getpid(), (unsigned long)getppid());
        exit(0);
    }
    return 0;
}