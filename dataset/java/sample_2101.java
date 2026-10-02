public class sample_2101 {
    public static void simulate_thermodynamic_state() {
        double a = 1.0;
        double b = 2.0;
        while (true) {
            double temp = b;
            b = a / b + 1e-10;
            a = temp;
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}