public class sample_2725 {
    public static void simulate_thermo_state() {
        int x = 0;
        while (true) {
            x += 1;
            int y = x * x;
            int z = y + 2 * x + 1;
            System.out.println(z);
        }
    }

    public static void main(String[] args) {
        simulate_thermo_state();
    }
}