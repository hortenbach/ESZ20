# ESZ20

weitere Anmerkungen zu den jeweiligen Aufgaben sind in seperaten readmes in den jeweiligen Ordnern.

## TODOs
bis 08.05.

### Aufgabe 1
läuft
### Aufgabe 2
läuft
#### Terminal größe
Gefragte Infos stecken in struct TIOCGWINSZ bei ioctl.
Man erhält jeweils ein int für zeilen und spalten.
#### Ascii-Art
Das ASCII-Art geprinte könnte unabhängig vom ioctl zeug geschrieben werden.
#### sleep
5 sekunden warten mit nanosleep
### Aufgabe 3
läuft  
Könnte verbessert werden:
- Funktioniert nur zuverlässig bei einer Mindestbreite des Terminalfensters
	- evtl. Fensterbreite auslesen und line[] dann mit der Breite initialisieren? --> führt bei mir dazu dass der Compiler meckert, wenn ich line[serial.ws_col]={' '} initialisiere, da er zu Programmstart nicht die Größe kennt.
