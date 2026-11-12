# Uni-Projekte – Wirtschaftsinformatik (HTWG Konstanz)

Übungs- und Laborprojekte aus meinem Studium der Wirtschaftsinformatik (B.Sc.) an der HTWG Konstanz, 2. Semester.
Schwerpunkte: Shell-Scripting unter Linux, Java-Grundlagen sowie C/C++ im Fach Betriebssysteme.

## Inhalt

| Projekt | Sprache | Beschreibung |
|---|---|---|
| [01 – Dezimal-Umrechner](shell/01-dezimal-umrechner) | Bash | Rechnet eine Dezimalzahl in Binär, Oktal oder Hexadezimal um (Restwert-Division) |
| [02 – Binär-Umrechner](shell/02-binaer-umrechner) | Bash | Rechnet Oktal-, Dezimal- und Hexadezimalzahlen ins Binärsystem um, inkl. Prüfung auf ungültige Ziffern |
| [Lab 1 – Lineare Suche](java/lab1-lineare-suche) | Java | Laufzeitmessung der linearen Suche bei wachsender Arraygröße (70 Mio. bis 520 Mio. Elemente) |
| [Lab 2 – Snake](java/lab2-snake) | Java | Snake-Spiel auf Basis eines vorgegebenen Gerüsts; von mir ergänzt: Richtungssperre, sichtbare Wand, Wand- und Selbstkollision, Fressen/Wachsen, Pellet-Platzierung |
| [Lab 3 – Homage to the Square](java/lab3-homage) | Java | Rekursiv verschachtelte Quadrate in Zufallsfarben nach Josef Albers; von mir: die rekursive Methode `drawSquares` und ihr Start aus `paint()` |
| [Lab 2.1 – Process Scheduling](c/lab2.1-scheduling) | C | CPU-Scheduler mit FCFS und SJF auf einer selbst gebauten verketteten Liste mit `malloc`/`free`; von mir: `struct.h`, `MySchedule.h`, `myScheduler.c` |
| [Lab 2.2 – Process Scheduling](cpp/lab2.2-scheduling) | C++ | CPU-Scheduler mit FCFS und SJF auf einer selbst verwalteten verketteten Liste; von mir: `Process.cpp`, die Listenmethoden in `ProcessList.cpp` und `Scheduler.cpp` |

## Shell-Skripte ausführen

Beide Skripte laufen interaktiv (ohne Argumente) oder direkt mit Argumenten:

```bash
# 01: Auswahl 1 = Binär, 2 = Oktal, 3 = Hexadezimal
./shell/01-dezimal-umrechner/uebung1.sh 3 255     # -> FF

# 02: Auswahl O = Oktal, D = Dezimal, H = Hexadezimal (Ausgabe jeweils binär)
./shell/02-binaer-umrechner/uebung1_2.sh O 17     # -> 001111
./shell/02-binaer-umrechner/uebung1_2.sh D 5      # -> 101
```

## Java-Lab ausführen

`Lab1_Teil1.java` nutzt eine instanzbasierte `void main()`-Methode und braucht daher **Java 25** (bzw. Java 21+ mit `--enable-preview`).
Das größte Array belegt rund 2 GB, deshalb muss der Heap vergrößert werden:

```bash
cd java/lab1-lineare-suche
java -Xmx6g Lab1_Teil1.java
```

Gesucht wird bewusst ein Wert (100000), der nicht im Array vorkommt (Zufallswerte 0–9999). So wird immer der Worst Case gemessen und die lineare Laufzeit O(n) sichtbar: Bei doppelter Arraygröße verdoppelt sich ungefähr die Suchzeit.

## C/C++-Labs ausführen

```bash
# Lab 2.1 (C)
cd c/lab2.1-scheduling
gcc -Wall -o scheduler main.c myScheduler.c
./scheduler

# Lab 2.2 (C++)
cd cpp/lab2.2-scheduling
g++ -Wall -o scheduler Main.cpp Process.cpp ProcessList.cpp Scheduler.cpp
./scheduler
```

## Was ich dabei gelernt habe

- Zahlensysteme und Umrechnung per Restwert-Division bzw. Ziffernzuordnung
- Bash: `case`, `while`, Arithmetik mit `$(( ))`, String-Slicing `${var:i:1}`, Argumente vs. interaktive Eingabe
- Java: Arrays, Laufzeitmessung mit `System.nanoTime()`, Komplexität der linearen Suche
- Java: Spielschleife, `enum`, `LinkedList`, Kollisionserkennung mit `Rectangle`, Arbeiten mit vorgegebenem Code
- Java: Rekursion (Basisfall, rekursiver Schritt), Zeichnen mit `Graphics` und zufälligen RGB-Farben
- C: `struct`, Zeiger, `malloc`/`free`, verkettete Liste mit `head` und `tail`
- C++: Klassen, Konstruktor/Destruktor, Zeiger und `->`, verkettete Listen, `new`/`delete` und Speicherverantwortung
