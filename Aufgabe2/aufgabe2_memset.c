#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>
#include <string.h>

int main(){

    // Fenstergroesse ermitteln
    struct winsize serial;
    ioctl(STDIN_FILENO, TIOCGWINSZ , &serial);

    if((serial.ws_col | serial.ws_row) < 3){
      perror("Minimum Terminal size is 3x3\n");
      return 1;
    }

    char line[serial.ws_col];
    char topbottom[serial.ws_col];
    char buffer[serial.ws_col];
    memset(line, 0, sizeof(line));
    memset(topbottom, '-', sizeof(topbottom));
    memset(buffer, ' ', sizeof(buffer));

    // Fenstergroesse printen
    sprintf(line,"rows: %hi\n",serial.ws_row);
    write(STDOUT_FILENO, line, sizeof(line));
    sprintf(line,"cols: %hi\n",serial.ws_col);
    write(STDOUT_FILENO, line, sizeof(line));

    // Delay um 5 Sekunden
    const struct timespec req =  { .tv_sec = 5, .tv_nsec = 0 } ;
    struct timespec rem;
    nanosleep(&req,&rem);

    /*  build top and bottom line */
    *topbottom = '+';
    *(topbottom + serial.ws_col-1) = '+';

    /*  build body */
    *buffer= '|';
    *(buffer + serial.ws_col-1) = '|';

    /*  print frame top */
    write(STDOUT_FILENO, topbottom, sizeof(topbottom)/sizeof(char));

    /*  print frame body */
    for(int i = 0; i < (serial.ws_row-2); i++){
      write(STDOUT_FILENO, buffer, sizeof(buffer)/sizeof(char));
    }

    /*  print frame bottom*/
    write(STDOUT_FILENO, topbottom, sizeof(topbottom)/sizeof(char));

    nanosleep(&req,&rem);

    return 0;
}
