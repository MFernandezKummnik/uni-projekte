# Lab 2 – Snake (ALDA)

Klassisches Snake-Spiel in Java (AWT/Swing). Die Schlange wird mit den Pfeiltasten gesteuert, frisst rote Pellets und wächst dabei. Das Spiel endet, wenn sie die Wand oder sich selbst trifft.

## Ausgangslage

Von der Professorin war ein **Code-Gerüst** vorgegeben: Fenster, Zeichnen, Tastatursteuerung, Spielschleife und die Bewegung der Schlange als `LinkedList<Rectangle>`. Meine Aufgabe war, die fehlende Spiellogik zu ergänzen und Fehler zu beheben.

Meine Zeilen sind im Code mit Kommentaren markiert (`//I ADDED …`, `//MY CODE START` … `//MY CODE ENDS`, `//mycode`).

## Meine Ergänzungen

| Ergänzung | Wo | Was sie macht |
|---|---|---|
| **Richtungssperre** | `keyPressed()` | Die Schlange kann nicht mit einem Tastendruck direkt umkehren (z. B. von rechts nach links) und in sich selbst laufen. Geprüft wird gegen `lastMoved`, also die Richtung des letzten tatsächlich ausgeführten Schritts, nicht gegen die zuletzt gedrückte Taste. So hilft auch schnelles Drücken von zwei Tasten innerhalb eines Spieltakts nicht, die Sperre zu umgehen. |
| **Wandkollision** | `run()` | Liegt der neue Kopf auf dem grauen Rand (`newX <= 0`, `newX >= WIDTH - SIZE`, analog für `y`), endet das Spiel. |
| **Selbstkollision** | `run()` | Der neue Kopf wird mit `equals()` gegen alle Segmente verglichen. `Rectangle.equals()` vergleicht Position und Größe, nicht die Objektidentität. |
| **Fressen und Wachsen** | `run()` | Trifft der Kopf das Pellet (`intersects()`), wird ein neues platziert und das letzte Segment **nicht** entfernt – die Schlange wird um ein Feld länger. Sonst wird das letzte Segment entfernt, die Länge bleibt gleich. |
| **Neues Pellet** | `placePellet()` | Zufällige Position im Raster: `(1 + random.nextInt(WIDTH / SIZE - 2)) * SIZE`. Die Multiplikation mit `SIZE` hält das Pellet im 10-Pixel-Raster der Schlange, `1 + …` und `- 2` halten es aus dem Rand heraus. |

## Ausführen

```bash
cd java/lab2-snake
javac Snake.java
java Snake
```

Hinweis: Der direkte Start mit `java Snake.java` (ohne vorheriges Kompilieren) funktioniert hier nicht, weil `enum Direction` als erster Typ in der Datei steht und der Single-File-Launcher dort die `main`-Methode sucht.

## Was ich dabei gelernt habe

- Mit vorgegebenem Code arbeiten: erst verstehen, dann gezielt ergänzen
- Spielschleife mit festem Takt, Zustand über `enum` (`Direction`)
- `LinkedList` als Schlange: `addFirst()` für den neuen Kopf, `removeLast()` für das Ende
- Kollisionserkennung mit `Rectangle` (`equals()` vs. `intersects()`)
- Zufallspositionen in einem Raster berechnen
