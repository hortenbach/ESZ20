#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int main(){

    char buffer;
    int irq_fd = open("/proc/interrupts", O_RDONLY);

    while (read(irq_fd, &buffer, 1) > 0){
        printf("%c", buffer);
    }
    close(irq_fd);

    return 0;
}
