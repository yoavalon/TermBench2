public class sample_1814 {
    public static int simulate_thermo_state() {
        double a = 0.1, b = 0.2, c = 0.3;
        for (int i = 0; i < 1000; i++) {
            a += b;
            if (Math.abs(a - c) < 1e-09) {
                return i + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        simulate_thermo_state();
    }
}