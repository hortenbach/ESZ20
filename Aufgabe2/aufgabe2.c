#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


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
    struct winsize ptr_serial;
    int fd = open("/dev/tty0", O_RDONLY);
    ioctl(fd, TIOCGWINSZ , &ptr_serial);
    printf("rows: %d \n", ptr_serial.ws_row);
    printf("columns: %d \n", ptr_serial.ws_col);
    close(fd);

    return 0;
}
