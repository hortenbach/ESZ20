#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>

/* int ioctl(int fd, unsigned long request, ...); */
/*

       TIOCGWINSZ     struct winsize *argp
              Get window size.

       TIOCSWINSZ     const struct winsize *argp
              Set window size.

       The struct used by these ioctls is defined as

           struct winsize {
               unsigned short ws_row;
               unsigned short ws_col;
               unsigned short ws_xpixel;   /* unused *//*
               unsigned short ws_ypixel;   /* unused *//*
           };

*/


int main(){

    char buffer;
    struct winsize serial;
    int fd = open("/dev/tty0", O_RDONLY);
    ioctl(STDIN_FILENO, TIOCGWINSZ , &serial);
    printf("rows: %hi \n", serial.ws_row);
    printf("columns: %d \n", serial.ws_col);
    const struct timespec req =  { .tv_sec = 5, .tv_nsec = 0 } ;
    struct timespec rem;
    nanosleep(&req,&rem);
    printf("5 seconds passed.\n");
    close(fd);

    return 0;
}
