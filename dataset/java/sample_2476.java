public class sample_2476 {
    public static int process_sequence(int[] sequence) {
        int state = 0;
        int[][] transitions = {
            {1, 2},
            {3, 0},
            {0, 3},
            {2, 1}
        };
        for (int bit : sequence) {
            state = transitions[state][bit];
        }
        return state;
    }

    public static void main(String[] args) {
        int[] sequence = {0, 1, 0, 1, 1, 0, 0};
        int result = process_sequence(sequence);
        System.out.println(result);
    }
}