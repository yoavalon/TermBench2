public class sample_2129 {
    public static void simulate_thermodynamic_state() {
        double a = 1.0, b = 2.0;
        while (true) {
            double c = (a + b) / 2;
            if (Math.abs(b - a) < 1e-10) {
                a = c;
                b = c + 1e-12;
            } else {
                a = c;
                b = b;
            }
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}