# Übung 1 – Dezimal-Umrechner (Bash)

Bash-Skript, das eine Dezimalzahl in das **Binär-, Oktal- oder Hexadezimalsystem** umrechnet.

## Bedienung

Das Skript läuft auf zwei Arten:

- **Interaktiv** (ohne Argumente): Es fragt nach dem Zielsystem (1 = Binär, 2 = Oktal, 3 = Hexadezimal, 4 = Exit) und danach nach der Zahl.
- **Mit Argumenten**: erstes Argument = Zielsystem, zweites = Zahl.

```bash
./uebung1.sh            # interaktiv
./uebung1.sh 1 10       # -> 1010
./uebung1.sh 2 64       # -> 100
./uebung1.sh 3 255      # -> FF
```

Sonderfälle: `0` ergibt `0`, negative Zahlen ergeben `-1`, eine unbekannte Auswahl ergibt „ungültige Auswahl“.

## Wie es funktioniert

| Teil | Was er macht |
|---|---|
| **Argumente prüfen** | `if [ $# -eq 0 ]` unterscheidet zwischen interaktivem Modus (`read`) und Aufruf mit Argumenten (`$1`, `$2`). |
| **Auswahl** | Ein `case` wählt je nach Zielsystem den passenden Zweig. |
| **Restwert-Division** | In einer `while`-Schleife wird die Zahl immer wieder durch die Basis (2, 8 oder 16) geteilt. Der Rest (`%`) ist die nächste Ziffer und wird **vorne** an das Ergebnis gehängt, weil die Reste von der niedrigsten Stelle aus entstehen. |
| **Hex-Ziffern** | Reste von 10 bis 15 werden über ein inneres `case` in `A` bis `F` übersetzt. |

## Ausführen

```bash
cd shell/01-dezimal-umrechner
chmod +x uebung1.sh
./uebung1.sh 3 255
```

## Was ich dabei gelernt habe

- Grundaufbau eines Bash-Skripts (`#!/bin/bash`, `if`, `case`, `while`)
- Interaktive Eingabe mit `read` vs. Übergabe als Argumente (`$#`, `$1`, `$2`)
- Rechnen in Bash mit `$(( ))`, Ganzzahldivision und Modulo
- Umrechnung von Zahlensystemen per Restwert-Division

Beim Shell-Scripting hat mir meine Vorerfahrung aus dem Bau meines eigenen Homeservers sehr geholfen: Mit der Linux-Kommandozeile, Bash und SSH hatte ich dort schon viel gearbeitet.
