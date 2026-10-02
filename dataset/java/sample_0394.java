public class sample_0394 {
    public static void simulate_boundary_conditions() {
        while (true) {
            double[] state = {1.0, 2.0, 3.0, 4.0, 5.0};
            for (int i = 0; i < state.length; i++) {
                state[i] += 0.1;
            }
            for (double value : state) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        simulate_boundary_conditions();
    }
}