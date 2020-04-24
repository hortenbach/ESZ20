# Aufgabenblatt 1
### Aufgabenstellung
Lesen Sie open(2), read(2), write(2) und close(2). Verwenden Sie diese Funktionen, um ein Programm zu schreiben, dass /proc/interrupts ausliest und auf die Standardausgabe ausgibt. Checken Sie das Programm in Ihr git-Repository unter dem Namen aufgabe1.c ein und taggen Sie die abgegebene Version mit dem Tag aufgabe1 (kleines a, kein Leerzeichen). Sie können gerne weitere Dateien einchecken, wie z.B. ein Makefile oder Projektdateien einer IDE.

## Fragen/Antworten zu den Themen

### Was ist der Unterschied zwischen printf und write? 
-> https://stackoverflow.com/questions/21084218/difference-between-write-and-printf

### Was ist die Standardausgabe (stdout) überhaupt? 
-> https://en.wikipedia.org/wiki/Standard_streams
#### Standard output (stdout)

Standard output is a stream to which a program writes its output data. The program requests data transfer with the write operation. Not all programs generate output. For example, the file rename command (variously called mv, move, or ren) is silent on success.

**Unless redirected, standard output is inherited from the parent process. In the case of an interactive shell, that is usually the text terminal which initiated the program.** (desshalb wird der text einfach ins terminal gerintet von dem wir aufgerufen haben)

The file descriptor for standard output is 1 (one); the POSIX <unistd.h> definition is STDOUT_FILENO; the corresponding C <stdio.h> variable is FILE* stdout; similarly, the C++ <iostream> variable is std::cout. 
