public class sample_2411 {
    public static void main(String[] args) {
        simulate_thermodynamic_state(10);
    }

    public static void simulate_thermodynamic_state(int n) {
        int x = 1, y = 1, z = 1;
        for (int i = 0; i < n; i++) {
            int tempX = x + y + z;
            int tempY = y + z;
            z = tempY;
            y = tempX;
            x = tempY;
        }
        System.out.println("(" + x + ", " + y + ", " + z + ")");
    }
}