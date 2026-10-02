public class sample_0336 {
    public static void simulate_state() {
        int x = 1, y = 1;
        while (true) {
            x = x + y;
            y = x - y;
            if (x == 0) {
                x = 1;
                y = 1;
            }
        }
    }

    public static void main(String[] args) {
        simulate_state();
    }
}