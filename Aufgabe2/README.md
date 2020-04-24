# Aufgabenblatt 2
Lesen Sie ioctl(2), ioctl_tty(2) oder tty_ioctl(4), sowie nanosleep(2). Schreiben Sie ein Programm, das die Größe des Terminalfensters ermittelt, ausgibt, und für ASCII-Art verwendet. Verwenden Sie dafür ausschließlich die genannten Systemrufe sowie die von Arbeitsblatt 1. Zur formatierten Ausgabe können Sie sprintf verwenden. Gehen Sie dabei wie folgt vor:

    das Programm ermittelt zunächst die Größe des Fensters und gibt sie aus
    das Programm wartet 5 Sekunden
    das Programm zeichnet einen Rahmen am Rand des Bildschirms, mit den Zeichen +, - und |.
    das Programm wartet 5 Sekunden
    es beendet sich.

Checken Sie Ihr Programm unter dem Namen aufgabe2.c in Ihr git-Repository ein.
