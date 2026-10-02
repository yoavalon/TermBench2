public class sample_1553 {
    public static void simulate_flight() {
        int x = 0, y = 0;
        int dx = 5, dy = 2;
        while (true) {
            x += dx;
            y += dy;
            if (y > 100) {
                dy = -dy;
            }
            if (x > 500) {
                dx = -dx;
            }
            System.out.println("Position: (" + x + ", " + y + ")");
        }
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}