# Aufgabenstellung
Verändern Sie Ihre Lösung von Aufgabe 3 derart, dass das Programm auf einer Echtzeitpriorität laufen kann. Diese Möglichkeit soll durch Kommandozeilenargumente gesteuert werden wie folgt:

   * kein zusätzliches Kommandozeilenargument: Programm verhält sich wie in Aufgabe 3
   * ein zusätzliches Argument: Argument gibt die Echtzeit-Priorität an. Die konkrete Scheduling-Klasse können Sie frei wählen.

Hinweis (zur Erinnerung): Die Kommandozeilenargumente können in einem C-Programm über die main-Argumente argc und argv ausgewertet werden.

Für die Rücksprache: führen Sie Ihr Programm mehrfach aus, und beobachten Sie die Zeiten. Lassen Sie dazu ein oder zwei Kopien des Programms auf einer Echtzeitpriorität laufen, und weitere Kopien nicht. Analysieren Sie die Auslastung mit top(1).

# Notes
- parallele Ausführung mehrere Instanzen via "sudo ./aufgabe4 10 & sudo ./aufgabe4 80 && fg"
