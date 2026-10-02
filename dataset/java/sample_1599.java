public class sample_1599 {
    public static void simulate_state_changes() {
        while (true) {
            double[] state = new double[10];
            for (int i = 0; i < state.length; i++) {
                state[i] += 0.1;
                if (state[i] > 1.0) {
                    state[i] -= 1.0;
                }
            }
        }
    }

    public static void main(String[] args) {
        simulate_state_changes();
    }
}