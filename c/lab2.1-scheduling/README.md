# Lab 2.1 – Process Scheduling in C (Betriebssysteme)

Simulation eines CPU-Schedulers in C. Wartende Prozesse liegen in einer selbst gebauten, einfach verketteten Liste (kein Array). Der Scheduler wählt daraus den nächsten Prozess nach einem von zwei Verfahren aus:

- **FCFS** (First Come, First Served): Der Prozess, der am längsten wartet, kommt zuerst dran.
- **SJF** (Shortest Job First): Der Prozess mit der kürzesten benötigten Rechenzeit kommt zuerst dran.

Die C++-Variante derselben Aufgabe liegt unter [`cpp/lab2.2-scheduling`](../../cpp/lab2.2-scheduling).

## Ausgangslage

Vorgegeben waren (und durften nicht verändert werden):

- `main.c`: Testprogramm mit vier Tests und einem Stresstest
- `process.h`: der Datentyp `process` mit `pid` und `time`

`main.c` bindet eine Datei `MySchedule.h` ein, die in der Aufgabenstellung nicht erwähnt wird. Ohne sie lässt sich das Programm nicht übersetzen, deshalb habe ich sie zusätzlich angelegt.

## Meine Dateien

| Datei | Inhalt |
|---|---|
| `struct.h` | Der Listenknoten: ein `process` plus Zeiger `next` auf den nächsten Knoten. |
| `MySchedule.h` | Die Prototypen von `myNewProcess()` und `mySchedule()`, damit `main.c` sie kennt. |
| `myScheduler.c` | Die Liste (`head` und `tail` als `static`-Zeiger) und die beiden Funktionen. |

**`myNewProcess()`** legt mit `malloc` einen neuen Knoten an, kopiert den Prozess hinein und hängt ihn hinten an. Der `tail`-Zeiger sorgt dafür, dass dafür nicht die ganze Liste durchlaufen werden muss.

**`mySchedule()`** gibt bei leerer Liste den Prozess `{0, 0}` zurück. Bei FCFS wird der erste Knoten entnommen, bei SJF die Liste nach dem Knoten mit der kleinsten Zeit durchsucht (bei Gleichstand bleibt der früher eingefügte), wobei der Vorgänger mitgeführt wird. Beim Entfernen gilt die Reihenfolge: Daten sichern, Zeiger umbiegen (inklusive `tail`, falls der letzte Knoten entfernt wird) und erst danach `free`.

`vorneEinfuegen()` und `alleAusgeben()` sind Übungsfunktionen aus der Einarbeitung in die Zeigersyntax und werden von `main.c` nicht benutzt.

## Ausführen

```bash
cd c/lab2.1-scheduling
gcc -Wall -o scheduler main.c myScheduler.c
./scheduler
```

Erwartete Ausgabe: `Test 1–4: passed`, `All tests passed` und die CPU-Zeit in Clock-Ticks (unter Linux 1.000.000 Ticks pro Sekunde, bei mir rund 0,2 s).

## Was ich dabei gelernt habe

- C-Grundlagen: `struct`, `typedef`, Header und Include Guards, Prototypen
- Zeiger: `*`, `&`, `.` vs. `->`, `NULL`
- Dynamischer Speicher mit `malloc` und `free`, Reihenfolge beim Freigeben („Use after free“ vermeiden)
- Lokale vs. globale (`static`) Variablen
- Klassische C-Fallen: `=` statt `==`, uninitialisierte Variablen, Kompilieren mit `-Wall`
- Verkettete Liste mit `head` und `tail`, Sonderfälle beim Entfernen (Anfang, Mitte, Ende, leere Liste)

Die C-Syntax habe ich mir mit KI-Unterstützung erklären lassen, den Code habe ich selbst geschrieben und verstehe ihn.
