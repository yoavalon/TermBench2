public class sample_0094 {
    public static void main(String[] args) {
        simulate_boundary_conditions(550, 90, 10);
    }

    public static void simulate_boundary_conditions(int temp, int pressure, int iterations) {
        for (int _ = 0; _ < iterations; _++) {
            if (temp > 500) {
                temp -= 50;
            }
            if (pressure < 100) {
                pressure += 20;
            }
        }
        System.out.println("(" + temp + ", " + pressure + ")");
    }
}