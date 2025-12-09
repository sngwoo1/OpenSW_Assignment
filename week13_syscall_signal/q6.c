#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    struct sigaction sa_int;

    // SIG_DFL: 기본 동작 유지
    // + 만약 SIG_IGN로 설정하면 SIGINT가 왔을 때, 
    // 무시해버리기 때문에 pending 상태도 가지 않는다.
    sa_int.sa_handler = SIG_DFL;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = 0;

    sigaction(SIGINT, &sa_int, NULL);

    // signal block을 위한 sigset_t
    sigset_t block_set, prev_set;
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    sigprocmask(SIG_BLOCK, &block_set, &prev_set);
    printf("SIGINT blocked. ");

    // 5초동안 sleep
    printf("Sleeping for 5 seconds...\n");
    printf("Try Ctrl + C during sleep.\n");
    sleep(5);

    // SIGINT에 pending되었는지 판단
    // delivered: signal이 도착했고, handler가 실행됨
    // blocked: signal이 도착했지만, block 중이라 실행되지 않음 (sigprocmask)
    // pending: signal이 도착했지만, 아직 처리되지 못하고 대기 중

    // pending되었는지 판단한다 
    // = signal block 중에 SIGINT가 왔는지 확인하고 싶을 때
    // sigpending(sigset_t형 변수의 주소)
    // sigismember(sigset_t형 변수의 주소, 시그널 종류)

    sigset_t pending;

    // pending signal들의 정보를 확인
    sigpending(&pending); 

    if(sigismember(&pending, SIGINT))
    {
        printf("\n\nSIGINT is pending\n");
    }
    else
    {
        printf("\n\nSIGINT is not pending\n");
    }
}