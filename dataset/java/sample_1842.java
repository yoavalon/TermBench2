public class sample_1842 {
    public static double simulate_thermo_state() {
        double x = 0.0, y = 0.0, z = 0.0;
        for (int i = 0; i < 1000; i++) {
            x += 0.0001;
            y -= 0.0001;
            z = (x + y) * 10000;
        }
        return z;
    }

    public static void main(String[] args) {
        simulate_thermo_state();
    }
}