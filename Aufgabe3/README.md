# Aufgabenstellung
Folgende naive und rechenzeitaufwendige Funktion berechnet n^4.

double n_4(int n)
{
  int a,b,c,d;
  double s=0;
  for(a=1; a<=n; a++)
    for (b=1; b <=n; b++)
      for (c=1; c <= n; c++)
        for (d=1; d <=n; d++)
          s+=1;
  return s;
}

Schreiben Sie ein Programm, das in einer Schleife mit 10 Durchläufen n_4 mit immer größer werdenden Zahlen aufruft (z.B. 0, 5, 10, 15 usw.), und zwar so, dass der letzte Schleifendurchlauf zwischen 5s und 60s benötigt (auf Ihrer CPU). Geben Sie nach jedem Schleifendurchlauf den Wert von n, den Wert von n_4 und die während der Berechnung verstrichene Zeit aus. Messen Sie die Zeit mit Hilfe von gettimeofday.

Checken Sie Ihre Lösung als n_4.c in Ihr git-Repository ein und taggen Sie die Abgabe mit dem Tag aufgabe3. Das Programm wird in den Folgeaufgaben weiterentwickelt.

Für die Rücksprache: führen Sie Ihr Programm mehrfach aus, und beobachten Sie die Zeiten. Stellen Sie eine Theorie über die erwartete Laufzeit auf und wenden Sie die Theorie auf gemessenen Werte an.

### Nützliche Links
- Formatierung mit sprintf() https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
