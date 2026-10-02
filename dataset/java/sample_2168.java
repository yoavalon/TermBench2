public class sample_2168 {
    public static void simulate_thermodynamic_state() {
        double x = 0.1;
        double y = 0.2;
        double z = 0.3;
        while (true) {
            x = x + y;
            y = x - z;
            z = y + z;
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}