public class sample_0362 {
    public static void simulate_flight() {
        int x = 0;
        int y = 0;
        double v_x = 100;
        double v_y = 50;
        double g = 9.81;
        int t = 0;
        while (true) {
            x += v_x;
            y += v_y;
            v_y -= g;
            t += 1;
            if (y <= 0) {
                v_y = -v_y * 0.75;
                y = 0;
            }
        }
    }

    public static void main(String[] args) {
        simulate_flight();
    }
}