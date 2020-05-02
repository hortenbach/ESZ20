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

    struct winsize serial;
    ioctl(STDIN_FILENO, TIOCGWINSZ , &serial);
    printf("rows: %hi \n", serial.ws_row);
    printf("columns: %d \n", serial.ws_col);
    const struct timespec req =  { .tv_sec = 5, .tv_nsec = 0 } ;
    struct timespec rem;
    nanosleep(&req,&rem);
    printf("5 seconds passed.\n");
    char buffer[serial.ws_row*serial.ws_col];
    for(int i=0;i<serial.ws_row*serial.ws_col;i++){
      if(i==serial.ws_col || i==serial.ws_col*2-1 || i==serial.ws_col*serial.ws_row-1 || i==serial.ws_col*(serial.ws_row-1)){
        buffer[i]='+';
      }else{
        if(i<serial.ws_col*2-1){
          buffer[i]='-';
        }else{
          if(i%serial.ws_col==0 || i%serial.ws_col==serial.ws_col-1){
            buffer[i]='|';
          }else{
            if(i>(serial.ws_row-1)*serial.ws_col){
              buffer[i]='-';
            }else{
              buffer[i]=' ';
            }
          }
        }
      }
    }
    write(STDOUT_FILENO, &buffer[0], sizeof(buffer)/sizeof(char));

    return 0;
}
