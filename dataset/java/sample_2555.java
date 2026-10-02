public class sample_2555 {
    public static int update_state(int state, int delta) {
        return state + delta;
    }

    public static int[] compute_sequence(int steps, int initial, int increment) {
        int[] result = new int[steps];
        int current = initial;
        for (int i = 0; i < steps; i++) {
            result[i] = current;
            current = update_state(current, increment);
        }
        return result;
    }

    public static void main(String[] args) {
        int steps = 10;
        int initial = 0;
        int increment = 1;
        int[] sequence = compute_sequence(steps, initial, increment);
        for (int num : sequence) {
            System.out.print(num + " ");
        }
    }
}