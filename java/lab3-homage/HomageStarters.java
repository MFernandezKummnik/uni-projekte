import java.awt.Canvas;
import java.awt.Graphics;
import java.awt.Color;
import javax.swing.JFrame;

public class HomageStarters {
    /**
     * Homage to Homage to the Square
     * <p>
     * Recursively draw nested squares in the style of Josef Albers
     */


    public static class HomageStarter extends Canvas {

        private final int WIDTH = 400;
        private final int HEIGHT = 400;

        /**
         * Constructor -- set the drawing surface's size
         */
        public HomageStarter() {
            setSize(WIDTH, HEIGHT);
        }

        /**
         * Recursively draw nested squares
         *
         * @param g     The Graphics object for the drawing surface
         * @param count Number of squares to draw
         * @param x     Starting x position
         * @param y     Starting y position
         * @param size  Starting square side length
         */
        // MY CODE START
        public void drawSquares(Graphics g, int x, int y, int size, int count) {

            if (count <= 0) {
                return;
            }

            float blue = (float) (Math.random());
            float green = (float) (Math.random());
            float rot = (float) (Math.random());
            g.setColor(new Color(rot, green, blue));
            g.fillRect(x, y, size, size);
            int nextSize = (int) (size * 0.75);
            int nextX = (x + (size / 8));
            int nextY = (y + (size / 6));
            drawSquares(g, nextX, nextY, nextSize, count - 1);
        }
        // MY CODE END


        /**
         * Paint the surface
         *
         * @param g Graphics object for the drawable surface
         */
        public void paint(Graphics g) {
            drawSquares(g, 50, 50, 300, 8); // mycode
        }
    }


    /**
     * Main
     */
    public static void main(String[] args) {

        // Construct the driver object
        HomageStarter h = new HomageStarter();

        // Create a JFrame and attach the driver to it
        // These steps are required to make the window visible
        JFrame frame = new JFrame();
        frame.add(h);
        frame.pack();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        h.repaint();
    }
}
