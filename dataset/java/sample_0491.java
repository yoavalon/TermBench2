public class sample_0491 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        int current = 0;
        for (int i = 0; i < n; i++) {
            sequence[i] = current;
            if (current == 0) {
                current += 1;
            } else {
                current = 0;
            }
        }
        return sequence;
    }

    public static void track_sequence(int[] seq) {
        int index = 0;
        while (true) {
            System.out.println(seq[index]);
            index = (index + 1) % seq.length;
        }
    }

    public static void main(String[] args) {
        int[] sequence = generate_sequence(10);
        track_sequence(sequence);
    }
}