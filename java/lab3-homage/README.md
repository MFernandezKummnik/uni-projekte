# Lab 3 – Homage to Homage to the Square (ALDA)

Java-Grafikprogramm (AWT/Swing), das rekursiv ineinander verschachtelte Quadrate in zufälligen Farben zeichnet – angelehnt an die Bilderserie *Homage to the Square* von Josef Albers.

## Ausgangslage

Vorgegeben war das Gerüst `HomageStarters.java`: Zeichenfläche (`Canvas`, 400 × 400), leere `paint()`-Methode und `main()` mit dem `JFrame`. Meine Aufgabe war die rekursive Methode `drawSquares` und ihr Start aus `paint()`.

Meine Zeilen sind im Code markiert (`// MY CODE START` … `// MY CODE END`, `// mycode`).

## Meine Ergänzungen

| Teil | Wo | Was er macht |
|---|---|---|
| **Basisfall** | `drawSquares()` | Ist `count <= 0`, beendet `return` die Rekursion. `<=` statt `==` schützt zusätzlich vor einer Endlosrekursion bei negativem Startwert. |
| **Zufallsfarbe** | `drawSquares()` | Drei zufällige `float`-Werte (0.0–1.0) für Rot, Grün und Blau ergeben über `new Color(r, g, b)` eine beliebige Farbe. |
| **Quadrat zeichnen** | `drawSquares()` | `g.fillRect(x, y, size, size)` zeichnet das aktuelle Quadrat. |
| **Verschachtelung** | `drawSquares()` | Nächstes Quadrat: 3/4 der Größe, um `size/8` nach rechts und `size/6` nach unten verschoben. Dadurch liegt es immer vollständig im vorherigen und wirkt leicht nach unten versetzt. |
| **Rekursiver Aufruf** | `drawSquares()` | Ruft sich mit den neuen Werten und `count - 1` selbst auf. |
| **Start** | `paint()` | `drawSquares(g, 50, 50, 300, 8)` startet die Rekursion einmal: 8 Quadrate, das äußerste 300 × 300 Pixel bei (50, 50). |

## Ausführen

```bash
cd java/lab3-homage
javac HomageStarters.java
java HomageStarters
```

Die Farben werden bei jedem Neuzeichnen (z. B. beim Verändern der Fenstergröße) neu ausgewürfelt.

## Was ich dabei gelernt habe

- Rekursion mit Basisfall, Zeichenschritt und rekursivem Schritt aufbauen
- Warum `paint()` nicht selbst aufgerufen wird: das `Graphics`-Objekt kommt vom System
- `static`-Methoden (`main`) vs. Objektmethoden (`drawSquares`)
- Ganzzahldivision und `(int)`-Casts: Größen schrumpfen bei kleinen Startwerten schnell auf 0
- Parameterreihenfolge muss exakt zur vorgegebenen Signatur passen

Die Lösung habe ich mit Unterstützung von KI (Claude) erarbeitet; den Code habe ich selbst geschrieben und verstehe ihn.
