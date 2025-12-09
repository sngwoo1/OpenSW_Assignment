#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{

    while(1)
    {
        pid_t pid = getpid();
        printf("%lu\n", (unsigned long)pid);
        sleep(1);        
    }

    return 0;
}