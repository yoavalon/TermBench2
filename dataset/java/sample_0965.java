public class sample_0965 {
    public static void cellular_automata(int[] state, int rule) {
        int size = state.length;
        int[] next_state = new int[size];
        for (int i = 0; i < size; i++) {
            int left = state[(i - 1 + size) % size];
            int center = state[i];
            int right = state[(i + 1) % size];
            int index = (left << 2) | (center << 1) | right;
            next_state[i] = (rule >> index) & 1;
        }
        cellular_automata(next_state, rule);
    }

    public static void main(String[] args) {
        int rule = 30;
        int[] initial_state = new int[21];
        initial_state[10] = 1;
        cellular_automata(initial_state, rule);
    }
}