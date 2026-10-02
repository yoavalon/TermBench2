public class sample_2814 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        sequence[0] = 0;
        sequence[1] = 1;
        for (int i = 2; i < n; i++) {
            sequence[i] = sequence[i - 1] + sequence[i - 2];
        }
        return sequence;
    }

    public static int[] process_sequence(int[] seq) {
        int[] processed = new int[seq.length];
        for (int i = 0; i < seq.length; i++) {
            processed[i] = seq[i] * i;
        }
        return processed;
    }

    public static void main(String[] args) {
        while (true) {
            int n = generate_sequence(10).length;
            int[] processed = process_sequence(generate_sequence(n));
            for (int value : processed) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}