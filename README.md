# Uni-Projekte – Wirtschaftsinformatik (HTWG Konstanz)

Hier sind meine Abgaben und Übungsaufgaben aus dem **2. Semester** meines Studiums der Wirtschaftsinformatik (B.Sc.) an der HTWG Konstanz. Sie umfassen **Java** (Algorithmen und Datenstrukturen), **C** und **C++** (Betriebssysteme) sowie **Shell-Scripting** unter Linux.

Jede Übung hat einen eigenen Ordner mit einem README. Dort steht, was vorgegeben war und was von mir stammt, wie das Programm funktioniert, wie man es ausführt und was ich dabei gelernt habe.

## Ordnerstruktur

```
uni-projekte/
├── java/
│   ├── lab1-lineare-suche/
│   ├── lab2-snake/
│   ├── lab3-homage/
│   └── lab4-quicksort/
├── c/
│   └── lab2.1-scheduling/
├── cpp/
│   └── lab2.2-scheduling/
└── shell/
    ├── 01-dezimal-umrechner/
    └── 02-binaer-umrechner/
```

## Java

| Übung | Beschreibung |
|---|---|
| [Lab 1 – Lineare Suche](java/lab1-lineare-suche) | Laufzeitmessung der linearen Suche bei wachsender Arraygröße (70 Mio. bis 520 Mio. Elemente) |
| [Lab 2 – Snake](java/lab2-snake) | Snake-Spiel auf Basis eines vorgegebenen Gerüsts; von mir ergänzt: Richtungssperre, sichtbare Wand, Wand- und Selbstkollision, Fressen/Wachsen, Pellet-Platzierung |
| [Lab 3 – Homage to the Square](java/lab3-homage) | Rekursiv verschachtelte Quadrate in Zufallsfarben nach Josef Albers; von mir: die rekursive Methode `drawSquares` und ihr Start aus `paint()` |
| [Lab 4 – Quicksort-Visualisierung](java/lab4-quicksort) | 50 Zufallsbalken werden animiert mit Quicksort sortiert (Median-aus-drei-Pivot, Lomuto-Partitionierung, Rekursion); bis auf das Grundgerüst selbst erarbeitet |

## C

| Übung | Beschreibung |
|---|---|
| [Lab 2.1 – Process Scheduling](c/lab2.1-scheduling) | CPU-Scheduler mit FCFS und SJF auf einer selbst gebauten verketteten Liste mit `malloc`/`free`; von mir: `struct.h`, `MySchedule.h`, `myScheduler.c` |

## C++

| Übung | Beschreibung |
|---|---|
| [Lab 2.2 – Process Scheduling](cpp/lab2.2-scheduling) | CPU-Scheduler mit FCFS und SJF auf einer selbst verwalteten verketteten Liste; von mir: `Process.cpp`, die Listenmethoden in `ProcessList.cpp` und `Scheduler.cpp` |

## Shell

| Übung | Beschreibung |
|---|---|
| [01 – Dezimal-Umrechner](shell/01-dezimal-umrechner) | Rechnet eine Dezimalzahl in Binär, Oktal oder Hexadezimal um (Restwert-Division) |
| [02 – Binär-Umrechner](shell/02-binaer-umrechner) | Rechnet Oktal-, Dezimal- und Hexadezimalzahlen ins Binärsystem um, inkl. Prüfung auf ungültige Ziffern |
