#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    handler(int signum)
{
    static char c = 0;
    static int bit = 0;

    if (signum == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        bit = 0;
        c = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);

    printf("PID : %d\n", getpid());
    usleep(200);
    while (1)
        pause();
    return (0);
}
