/**
 * Lab 1 - Teil 1: Laufzeitmessung der linearen Suche.
 *
 * Gesucht wird bewusst ein Wert, der nicht im Array vorkommt (Zufallswerte 0-9999,
 * gesucht wird 100000). So wird immer das gesamte Array durchlaufen (Worst Case, O(n)).
 *
 * Start (Java 25, bei Java 21+ mit --enable-preview):
 *   java -Xmx6g Lab1_Teil1.java
 */
public class Lab1_Teil1 {

    static final int GESUCHTER_WERT = 100_000;
    static final int[] GROESSEN = {70_000_000, 140_000_000, 280_000_000, 520_000_000};

    void main() {
        for (int groesse : GROESSEN) {
            int[] zahlen = zufallsArray(groesse);

            long start = System.nanoTime();
            int index = linearSearch(zahlen, GESUCHTER_WERT);
            long dauerNs = System.nanoTime() - start;

            System.out.printf("Groesse: %,d | Ergebnis: %d | Dauer: %.1f ms%n",
                    groesse, index, dauerNs / 1_000_000.0);
        }
    }

    /** Erzeugt ein Array mit Zufallszahlen im Bereich 0 bis 9999. */
    static int[] zufallsArray(int groesse) {
        int[] a = new int[groesse];
        for (int i = 0; i < a.length; i++) {
            a[i] = (int) (Math.random() * 10_000);
        }
        return a;
    }

    /** Gibt den Index von val zurück oder -1, falls der Wert nicht vorkommt. */
    static int linearSearch(int[] a, int val) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == val) {
                return i;
            }
        }
        return -1;
    }
}
