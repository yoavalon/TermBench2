public class sample_2141 {
    public static void simulate_thermodynamic_state() {
        double x = 0.0;
        while (true) {
            x += 0.0001;
            double y = 1 / x;
            if (y == 0) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}