import java.util.Arrays;

public class sample_1656 {
    public static Iterable<int[]> simulate_state(int[] state, int rate) {
        return () -> new java.util.Iterator<int[]>() {
            public boolean hasNext() {
                return true;
            }

            public int[] next() {
                state = mutate_state(state, rate);
                return state;
            }
        };
    }

    public static int[] mutate_state(int[] state, int rate) {
        for (int i = 0; i < state.length; i++) {
            if (state[i] > 0) {
                state[i] -= rate;
            } else {
                state[i] = 0;
            }
        }
        return state;
    }

    public static void main(String[] args) {
        int[] initial_state = {10, 20, 30, 40, 50};
        int mutation_rate = 5;
        for (int[] state : simulate_state(initial_state, mutation_rate)) {
            System.out.println(Arrays.toString(state));
        }
    }
}