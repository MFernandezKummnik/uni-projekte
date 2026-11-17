# Lab 1 – Laufzeitmessung der linearen Suche (ALDA)

Java-Programm, das misst, wie lange die **lineare Suche** in immer größeren Arrays braucht, und damit zeigt, dass ihre Laufzeit linear mit der Arraygröße wächst – O(n).

## Aufgabe

Ein Array wird mit Zufallszahlen von 0 bis 9999 gefüllt und anschließend Element für Element nach einem Wert durchsucht. Das passiert für vier Arraygrößen (70 Mio., 140 Mio., 280 Mio. und 520 Mio. Elemente), jeweils mit Zeitmessung.

## Aufbau

| Teil | Was er macht |
|---|---|
| `GESUCHTER_WERT` | Der gesuchte Wert ist 100000. Da die Zufallswerte nur bis 9999 gehen, kommt er **nie** vor – die Suche läuft also immer durch das ganze Array. So wird bewusst der **Worst Case** gemessen. |
| `GROESSEN` | Die vier Arraygrößen; jede ist etwa doppelt so groß wie die vorherige. |
| `zufallsArray()` | Erzeugt ein Array der gewünschten Größe mit Zufallswerten (`Math.random() * 10_000`). |
| `linearSearch()` | Geht das Array von vorne nach hinten durch und gibt den Index des Treffers zurück, oder `-1`, wenn der Wert nicht vorkommt. |
| `main()` | Misst für jede Größe mit `System.nanoTime()` nur die Suche (nicht das Befüllen) und gibt Größe, Ergebnis und Dauer in Millisekunden aus. |

## Ausführen

`Lab1_Teil1.java` nutzt eine instanzbasierte `void main()`-Methode und braucht daher **Java 25** (bzw. Java 21+ mit `--enable-preview`).
Das größte Array belegt rund 2 GB (520 Mio. × 4 Byte), deshalb muss der Heap vergrößert werden:

```bash
cd java/lab1-lineare-suche
java -Xmx6g Lab1_Teil1.java
```

Erwartetes Ergebnis: Bei doppelter Arraygröße verdoppelt sich ungefähr auch die Suchzeit.

## Was ich dabei gelernt habe

- Lineare Suche und ihre Komplexität O(n)
- Worst Case gezielt herbeiführen, damit die Messung aussagekräftig ist
- Laufzeitmessung mit `System.nanoTime()` und warum nur der gemessene Teil zwischen Start und Ende liegen darf
- Speicherbedarf großer Arrays abschätzen und den Heap mit `-Xmx` vergrößern
