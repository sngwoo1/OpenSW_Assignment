#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(void)
{
    pid_t my_pid;
    pid_t my_ppid;
    my_pid = getpid();
    my_ppid = getppid();
    printf("pid: %u\n", (unsigned int)my_pid);
    printf("ppid: %u\n", (unsigned int)my_ppid);

    return 0;
}
