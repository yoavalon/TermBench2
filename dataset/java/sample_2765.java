public class sample_2765 {
    public static void cellular_automata(int n) {
        int[] state = new int[n];
        state[n / 2] = 1;
        while (true) {
            int[] new_state = new int[n];
            for (int i = 1; i < n - 1; i++) {
                new_state[i] = state[i - 1] ^ state[i + 1];
            }
            state = new_state;
        }
    }

    public static void main(String[] args) {
        cellular_automata(30);
    }
}