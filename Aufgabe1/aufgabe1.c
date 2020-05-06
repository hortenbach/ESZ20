#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    char buffer;
    int irq_fd = open("/proc/interrupts", O_RDONLY);

    while(read(irq_fd, &buffer, 1) > 0){   // read returns 0 if we reach EOF
        write(STDOUT_FILENO, &buffer, 1);
    }
    close(irq_fd);

    return 0;
}
