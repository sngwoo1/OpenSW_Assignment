#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(void)
{
    pid_t my_pid;

    my_pid = getpid();

    printf("%u\n", (unsigned int)my_pid);
    return 0;
}
