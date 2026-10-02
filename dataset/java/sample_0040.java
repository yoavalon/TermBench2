public class sample_0040 {
    public static int simulate_thermodynamic_state() {
        int x = 0, y = 0, z = 0;
        while (x < 10) {
            x += 1;
            y += x;
            z += y;
        }
        return z;
    }

    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }
}