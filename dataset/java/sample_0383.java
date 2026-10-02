public class sample_0383 {
    public static void simulate_state() {
        double x = 0.1, y = 0.2, z = 0.3;
        while (true) {
            x = y;
            y = z;
            z = x + y + z;
            if (x > 1) {
                x = 0.1;
                y = 0.2;
                z = 0.3;
            }
        }
    }

    public static void main(String[] args) {
        simulate_state();
    }
}