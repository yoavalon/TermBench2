public class sample_1577 {
    public static void simulate_thermodynamic_state() {
        int energy = 0;
        int entropy = 0;
        while (true) {
            energy += 1;
            entropy += 1;
            if (energy > 100) {
                energy = 0;
            }
            if (entropy > 200) {
                entropy = 0;
            }
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}