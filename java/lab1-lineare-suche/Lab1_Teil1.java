public class Lab1_Teil1 {
    void main() {
        int[] zufallsZahlen = new int[70000000];
        for (int i = 0; i < zufallsZahlen.length; i++) {
            zufallsZahlen[i] = (int)(Math.random() * 10000);
        }
        double x =System.nanoTime();
        System.out.println(linearSearch(zufallsZahlen, 100000));
        double y = System.nanoTime()-x;
        System.out.println(y);
        int[] zufallsZahlen2 = new int[140000000];
        for (int i = 0; i < zufallsZahlen2.length; i++) {
            zufallsZahlen2[i] = (int)(Math.random() * 10000);
        }
        double x1 =System.nanoTime();
        System.out.println(linearSearch(zufallsZahlen2, 100000));
        double y1 = System.nanoTime()-x1;
        System.out.println(y1);
        int[] zufallsZahlen3 = new int[280000000];
        for (int i = 0; i < zufallsZahlen3.length; i++) {
            zufallsZahlen3[i] = (int)(Math.random() * 10000);
        }
        double x3 =System.nanoTime();
        System.out.println(linearSearch(zufallsZahlen3, 100000));
        double y3 = System.nanoTime()-x3;
        System.out.println(y3);
        int[] zufallsZahlen4 = new int[520000000];
        for (int i = 0; i < zufallsZahlen4.length; i++) {
            zufallsZahlen4[i] = (int)(Math.random() * 10000);
        }
        double x4 =System.nanoTime();
        System.out.println(linearSearch(zufallsZahlen4, 100000));
        double y4 = System.nanoTime()-x4;
        System.out.println(y4);
    }

    public int linearSearch(int[] a, int val) {
        for (int i = 0; i < a.length; i++) {
            if (val == a[i])
                return i;
        }
            return -1;

    }
}