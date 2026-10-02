public class sample_2787 {
    public static void simulate_thermodynamic_state() {
        double x = 0.5;
        while (true) {
            x = 3.9 * x * (1 - x);
            System.out.println(x);
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}