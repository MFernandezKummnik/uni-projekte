import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Color;
import javax.swing.JFrame;
import java.util.Arrays;
import java.util.Random;

    public class FractalsPt2 extends Canvas {

        private final int WIDTH = 400;
        private final int HEIGHT = 400;
        private final int[] a = new int[50];

        public FractalsPt2() {
            setSize(WIDTH, HEIGHT);
            Random rand = new Random();
            int min = 10;
            int max = 300;
            for (int i = 0; i<a.length; i++) {
                a[i] = rand.nextInt(max - min + 1) + min;
            }
        }

        public void paint(Graphics g) {
            g.setColor(Color.RED);
            drawbars(g,a);

        }
        public void drawbars(Graphics g, int[] a){

            int x = 0;
            for (int i = 0; i<a.length; i++) {
                g.fillRect(x,getHeight()-a[i],10, a[i]);
                x= x+10;

            }

        }
        public int partition(int[] b, int first, int last){
            int pivot;
            int mitte = (first+last)/2;
            if (b[first] <= b[mitte] && b[mitte] <= b[last] || b[first] >= b[mitte] && b[mitte] >= b[last]) {
                pivot = mitte ;
            }else if (b[first] <= b[last] && b[last] <= b[mitte] || b[first] >= b[last] && b[last] >= b[mitte]){
                pivot = last;
            }
            else {
                pivot =first;
            }
            System.out.println(pivot);
            int temp = b[pivot];
            b[pivot] = b[last];
            b[last] = temp;

            int pivotWert = b[last];
            int swap = first;

            for (int i = first; i < last; i++){
                if(b[i]<pivotWert){
                    temp = b[swap];
                    b[swap] = b[i];
                    b[i] = temp;
                    swap++;
                    repaint();
                    try {
                        Thread.sleep(20);
                    } catch (InterruptedException e) {}
                }
            }
            temp= b[swap];
            b[swap] = b[last];
            b[last] = temp;
            return swap;

        }
        public void quickSort(int[] a,int low, int high){
            if(low>=high){
                return;
            }
            int pivot = partition(a, low, high);
            quickSort(a, low,pivot-1);
            quickSort(a, pivot+1, high);

        }

        public static void main(String[] args) {

            // Construct the driver object
            FractalsPt2 h = new FractalsPt2();

            // Create a JFrame and attach the driver to it
            // These steps are required to make the window visible
            JFrame frame = new JFrame();
            frame.add(h);
            frame.pack();
            frame.setVisible(true);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            System.out.println("Vorher:  " + Arrays.toString(h.a));
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {}
            h.quickSort(h.a,0,h.a.length-1);
            h.repaint();

        }
    }