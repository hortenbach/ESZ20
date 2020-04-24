#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int n = 0;
    char buffer[3000];
    int irq_fd = open("/proc/interrupts", O_RDONLY);

    while (read(irq_fd, &buffer[n++], 1) > 0){
    }
    write(STDOUT_FILENO, &buffer[0], sizeof(buffer)/sizeof(char));
    close(irq_fd);

    return 0;
}
