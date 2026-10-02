public class sample_2161 {
    public static void simulate_state() {
        double a = 1.0, b = 1.0, c = 1.0;
        while (true) {
            a = (a + b) / 2;
            b = (b + c) / 2;
            c = (a + c) / 2;
        }
    }

    public static void main(String[] args) {
        simulate_state();
    }
}