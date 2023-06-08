#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void    send_bit(pid_t pid, char c, int bit)
{
    if ((c >> bit) & 1)
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);
}

void    send_char(pid_t pid, char c)
{
    int bit = 0;

    while (bit < 8)
    {
        send_bit(pid, c, bit);
        bit++;
        usleep(50);
    }
}

void    send_string(pid_t pid, char *str)
{
    while (*str)
        send_char(pid, *str++);
    send_char(pid, 0);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (1);
    send_string(atoi(argv[1]), argv[2]);
    return (0);
}
