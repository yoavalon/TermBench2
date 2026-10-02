public class sample_2730 {
    public static void simulate_thermodynamic_states() {
        int x = 1, y = 1, z = 1;
        while (true) {
            x = x + y;
            y = y + z;
            z = z + x;
            System.out.println(x + " " + y + " " + z);
        }
    }

    public static void main(String[] args) {
        simulate_thermodynamic_states();
    }
}