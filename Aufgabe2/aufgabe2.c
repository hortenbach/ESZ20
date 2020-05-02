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

    // Fenstergroesse ermitteln
    struct winsize serial;
    ioctl(STDIN_FILENO, TIOCGWINSZ , &serial);
    
    // Fenstergroesse printen
    char line[serial.ws_col];
    for(int i=0;i<=serial.ws_col;i++){
      line[i]=' ';
    }
    sprintf(line,"rows: %hi",serial.ws_row);
    write(STDOUT_FILENO, &line[0], sizeof(line)+1);
    sprintf(line,"cols: %hi",serial.ws_col);
    write(STDOUT_FILENO, &line[0], sizeof(line)+1);


    // Delay um 5 Sekunden
    const struct timespec req =  { .tv_sec = 5, .tv_nsec = 0 } ;
    struct timespec rem;
    nanosleep(&req,&rem);

    // Speichern eines Rahmen für die ermittelte Fenstergroesse mittels ASCII-Art am Rand des Bildschirms
    char buffer[serial.ws_row*serial.ws_col];
    for(int i=0;i<serial.ws_row*serial.ws_col;i++){
      if(i==serial.ws_col || i==serial.ws_col*2-1 || i==serial.ws_col*serial.ws_row-1 || i==serial.ws_col*(serial.ws_row-1)){
        buffer[i]='+';
      }else{
        if(i<serial.ws_col*2-1 && i>serial.ws_col){
          buffer[i]='-';
        }else{
          if((i%serial.ws_col==0 || i%serial.ws_col==serial.ws_col-1) && i>serial.ws_col) {
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

    // Printe den berechneten Rahmen
    write(STDOUT_FILENO, &buffer[0], sizeof(buffer)/sizeof(char));

    return 0;
}
