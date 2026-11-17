# Fractals Pt. 2 – Quicksort-Visualisierung (ALDA)

Java-Grafikprogramm (AWT/Swing), das 50 zufällig hohe Balken zeichnet und sie anschließend mit **Quicksort** sortiert. Jeder Tausch wird mit einer kurzen Pause neu gezeichnet, sodass man live sieht, wie sich das Diagramm Schritt für Schritt zu einer aufsteigenden Treppe ordnet.

## Ausgangslage

Übernommen wurde das bekannte Grundgerüst: Zeichenfläche (`Canvas`, 400 × 400), leere `paint()`-Methode und `main()` mit dem `JFrame`. Den Rest habe ich selbst erarbeitet.

## Meine Ergänzungen

| Teil | Wo | Was er macht |
|---|---|---|
| **Zufallswerte** | Konstruktor | Füllt das Attribut `a` (50 Werte) **einmal** mit Zufallszahlen von 10 bis 300 (`rand.nextInt(max - min + 1) + min`). Weil das im Konstruktor passiert, bleiben die Werte bei jedem `repaint()` gleich. |
| **Balken zeichnen** | `paint()` / `drawbars()` | Zeichnet jeden Wert als 10 px breiten Balken. Da y in Java nach unten wächst, beginnt jeder Balken bei `getHeight() - a[i]`, damit er am unteren Rand steht. |
| **Pivot-Wahl** | `partition()` | **Median aus drei** (erstes, mittleres, letztes Element) – vermeidet den O(n²)-Fall bei bereits sortierten Daten. |
| **Pivot parken** | `partition()` | Das Pivot wird ans Ende des Bereichs getauscht und sein **Wert** in `pivotWert` gespeichert. So wird es beim Durchlaufen nicht versehentlich weggetauscht. |
| **Aufteilen** | `partition()` | Lomuto-Verfahren: `swap` ist die Grenze – alles links davon ist kleiner als das Pivot. Kleinere Werte werden an die Grenze getauscht. |
| **Pivot einsetzen** | `partition()` | Zum Schluss wird das Pivot an die Stelle `swap` getauscht; diese Endposition wird zurückgegeben. |
| **Rekursion** | `quickSort()` | Basisfall `low >= high` (0 oder 1 Element ist sortiert), sonst aufteilen und linken (`low` bis `pivot-1`) sowie rechten Teil (`pivot+1` bis `high`) rekursiv sortieren. |
| **Animation** | `partition()` / `main()` | `repaint()` + `Thread.sleep(20)` nach jedem Tausch; in `main` 2 Sekunden Pause vor dem Sortieren, um den Ausgangszustand zu sehen. |

## Ausführen

```bash
cd java/lab4-quicksort
javac FractalsPt2.java
java FractalsPt2
```

In der Konsole wird das Array vor dem Sortieren ausgegeben.

## Was ich dabei gelernt habe

- Quicksort: Teile und herrsche, Pivot-Wahl, Partitionieren, Rekursion auf Teilbereichen
- Ein **Index** zeigt auf einen Platz, nicht auf einen Wert – beim Tauschen zieht er nicht mit
- Die Schleife in `partition` darf nur im Bereich `first` bis `last` arbeiten, sonst wird bereits Sortiertes wieder zerstört
- `partition` muss die **End**position des Pivots zurückgeben, nicht die ursprüngliche
- Koordinatensystem in Java: (0, 0) liegt oben links
- Attribute vs. lokale Variablen, und was direkt in einer Klasse stehen darf
- `repaint()` zeichnet nicht sofort: Animation funktioniert nur, wenn das Sortieren nicht im Zeichen-Thread (`paint`) läuft
