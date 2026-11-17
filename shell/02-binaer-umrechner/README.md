# Übung 2 – Binär-Umrechner (Bash)

Bash-Skript, das eine **Oktal-, Dezimal- oder Hexadezimalzahl ins Binärsystem** umrechnet – also die Gegenrichtung zu [Übung 1](../01-dezimal-umrechner). Ungültige Ziffern werden erkannt.

## Bedienung

Das Skript läuft auf zwei Arten:

- **Interaktiv** (ohne Argumente): Es fragt nach dem Ausgangssystem (O = Oktal, D = Dezimal, H = Hexadezimal) und danach nach der Zahl.
- **Mit Argumenten**: erstes Argument = Ausgangssystem, zweites = Zahl.

```bash
./uebung1_2.sh            # interaktiv
./uebung1_2.sh O 17       # -> 001111
./uebung1_2.sh D 5        # -> 101
./uebung1_2.sh H 1F       # -> 00011111
./uebung1_2.sh O 18       # -> ungültige Zahl (8 gibt es im Oktalsystem nicht)
```

## Wie es funktioniert

| Teil | Was er macht |
|---|---|
| **Ziffern einzeln lesen** | Mit String-Slicing `${zahl:$index:1}` wird die Zahl Zeichen für Zeichen durchgegangen; `${#zahl}` liefert die Länge. |
| **Gültigkeit prüfen** | Beim Oktal- und Dezimalsystem wird zuerst geprüft, ob Ziffern vorkommen, die es dort nicht gibt (z. B. `8`, `9` oder `A`–`F` bei Oktal). Dann wird ein Merker `ungueltig` gesetzt und nichts umgerechnet. |
| **Oktal → Binär** | Jede Oktalziffer entspricht genau **3 Bit** (z. B. `7` → `111`). Die Bitgruppen werden per `case` zugeordnet und aneinandergehängt. |
| **Hexadezimal → Binär** | Jede Hex-Ziffer entspricht genau **4 Bit** (z. B. `F` → `1111`), ebenfalls per `case` zugeordnet. |
| **Dezimal → Binär** | Hier gibt es keine feste Zuordnung pro Ziffer, deshalb Restwert-Division durch 2 wie in Übung 1. |

## Ausführen

```bash
cd shell/02-binaer-umrechner
chmod +x uebung1_2.sh
./uebung1_2.sh H 1F
```

## Was ich dabei gelernt habe

- String-Slicing in Bash (`${var:i:1}`) und Länge eines Strings (`${#var}`)
- Eingaben prüfen und mit einem Merker (Flag) auf Fehler reagieren
- Warum Oktal- und Hex-Ziffern direkt in 3- bzw. 4-Bit-Gruppen übersetzt werden können, Dezimalzahlen aber nicht
