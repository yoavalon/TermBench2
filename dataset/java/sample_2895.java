public class sample_2895 {
    public static int[] generate_sequence(int n) {
        int a = 0, b = 1;
        int[] sequence = new int[n];
        for (int i = 0; i < n; i++) {
            sequence[i] = a;
            int temp = a;
            a = b;
            b = temp + b;
        }
        return sequence;
    }

    public static int[] simulate_states(int[] seq) {
        int[] states = new int[seq.length];
        for (int i = 0; i < seq.length; i++) {
            states[i] = seq[i] * 2 + 1;
        }
        return states;
    }

    public static void main(String[] args) {
        while (true) {
            int n = 10;
            int[] sequence = generate_sequence(n);
            int[] states = simulate_states(sequence);
            for (int state : states) {
                System.out.print(state + " ");
            }
            System.out.println();
        }
    }
}