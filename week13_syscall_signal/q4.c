#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

void sigint_handler(int signum)
{
    printf("[SIGINT handler] ------------\n");

    // child process 생성
    pid_t pid = fork();

    // child process
    if(pid == 0) 
    {
        // execve 함수: OS에서 새 프로그램을 실행할 때 사용하는 시스템 콜
        char* args[] = {NULL};
        execve("/usr/bin/ls", args, NULL);
    }
    // parent process
    else
    {
        // child process의 종료를 기다림
        int wstatus;
        waitpid(pid, &wstatus, 0);
    }
}

void sigquit_handler(int signum)
{
    printf("[SIGQUIT handler] ------------\n");
    pid_t pid = fork();

    if(pid == 0) 
    {
        char* args[] = {NULL};
        execve("/usr/bin/date", args, NULL);
    }
    else
    {
        // child process의 종료를 기다림
        int wstatus;
        waitpid(pid, &wstatus, 0);
    }
}

void sigalrm_handler(int signum)
{
    printf("[SIGALRM handler] ------------\n");
    pid_t pid = fork();

    if(pid == 0) 
    {
        char* args[] = {NULL};
        execve("/usr/bin/whoami", args, NULL);
    }
    else
    {
        // child process의 종료를 기다림
        int wstatus;
        waitpid(pid, &wstatus, 0);
    }
    alarm(3);
}


int main(void)
{
    // 조건 1
    // sigalarm 설정 및 alarm 호출
    struct sigaction sa_int; // CTRL + C
    struct sigaction sa_quit; // CTRL + 역슬래쉬
    struct sigaction sa_alrm; // CTRL + Z

    sa_int.sa_handler = sigint_handler;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sa_quit.sa_handler = sigquit_handler;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = 0;

    sa_alrm.sa_flags = 0;
    sa_alrm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alrm.sa_mask);

    sigaction(SIGINT, &sa_int, NULL);
    sigaction(SIGQUIT, &sa_quit, NULL);
    sigaction(SIGALRM, &sa_alrm, NULL);

    alarm(3);

    while(1)
    {
        sleep(1);    
    }

    return 0;
}