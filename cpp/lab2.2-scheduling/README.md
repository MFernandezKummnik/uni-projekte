# Lab 2.2 – Process Scheduling in C++ (Betriebssysteme)

Simulation eines CPU-Schedulers in C++. Wartende Prozesse liegen in einer selbst verwalteten, einfach verketteten Liste. Der Scheduler wählt daraus den nächsten Prozess nach einem von zwei Verfahren aus:

- **FCFS** (First Come, First Served): Der Prozess, der am längsten wartet, kommt zuerst dran.
- **SJF** (Shortest Job First): Der Prozess mit der kürzesten benötigten Rechenzeit kommt zuerst dran.

## Ausgangslage

Vorgegeben waren (und durften nicht verändert werden):

- `Main.cpp`: Testprogramm mit vier Tests und einem Stresstest (30.000 Prozesse)
- `Process.H`, `ProcessList.H`, `Scheduler.H`: die Klassendefinitionen
- `ProcessList.cpp` zur Hälfte: Konstruktor, `insert_first()` und `show_all()`
- `Process.cpp` als leeres Gerüst (nur die Methodenköpfe)

## Meine Ergänzungen

| Datei | Methoden | Was sie machen |
|---|---|---|
| `Process.cpp` | Konstruktor, Destruktor, `set()`, `set_next()`, Getter | Konstruktor setzt `pid`/`time` auf 0 und `next` auf `NULL`. `set()` übernimmt die Werte und setzt `next` ebenfalls auf `NULL`. Der Destruktor bleibt bewusst leer, weil die Klasse selbst keinen Speicher anlegt. |
| `ProcessList.cpp` | `insert_last()` | Hängt einen Prozess hinten an. Da die Liste keinen `tail`-Zeiger hat (Header nicht änderbar), wird bis zum letzten Element gelaufen. Der `next`-Zeiger des neuen Prozesses wird vorher auf `NULL` gesetzt, weil `main` dieselben Prozessobjekte in mehreren Tests wiederverwendet. |
| `ProcessList.cpp` | `remove()` | Hängt einen bestimmten Prozess aus: am Anfang über `process_list`, sonst über die Suche nach dem Vorgänger. Gibt `NULL` zurück, wenn die Liste leer ist oder der Prozess nicht drin ist. Kein `delete`: Den Speicher gibt der Aufrufer frei. |
| `ProcessList.cpp` | `get_first()`, `get_next()`, `empty()` | Durchlaufen der Liste über das Lesezeichen `current`, abgesichert gegen `NULL`. |
| `Scheduler.cpp` | `myNewProcess()`, `mySchedule()` | Neu angelegt. Arbeitet ausschließlich mit den Methoden von `ProcessList`. FCFS nimmt das erste Element, SJF sucht das Element mit der kleinsten Zeit (bei Gleichstand das früher eingefügte). Bei leerer Liste wird `NULL` zurückgegeben. |

## Ausführen

```bash
cd cpp/lab2.2-scheduling
g++ -Wall -o scheduler Main.cpp Process.cpp ProcessList.cpp Scheduler.cpp
./scheduler
```

Erwartete Ausgabe: `Test 1–4: passed`, `All Test passed` und die gemessene CPU-Zeit in Clock-Ticks (unter Linux 1.000.000 Ticks pro Sekunde, bei mir rund 1,1 s). Die Laufzeit kommt fast vollständig von `insert_last()`, das ohne `tail`-Zeiger bei jedem Einfügen die ganze Liste durchläuft.

## Was ich dabei gelernt habe

- C++-Klassen: Trennung von Header (`.H`) und Umsetzung (`.cpp`), `Klasse::methode`
- Konstruktor und Destruktor, `this` als Zeiger (`this->`)
- Objekte (`.`) vs. Zeiger (`->`), `new`/`delete` und wer für das Freigeben zuständig ist
- Verkettete Listen nur über Getter und Setter verwalten, weil die Attribute `private` sind
- Sonderfälle beim Entfernen: Anfang, Mitte, Ende, leere Liste, nicht gefunden
- Auswirkung der Datenstruktur auf die Laufzeit (mit vs. ohne `tail`-Zeiger)

Die C++-Syntax habe ich mir mit KI-Unterstützung erklären lassen, den Code habe ich selbst geschrieben und verstehe ihn.
