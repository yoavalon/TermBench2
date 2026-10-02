public class sample_2503 {
    public static int[] seq_gen(int n) {
        int a = 0, b = 1;
        int[] sequence = new int[n];
        for (int _ = 0; _ < n; _++) {
            sequence[_] = a;
            int temp = a;
            a = b;
            b = temp + b;
        }
        return sequence;
    }

    public static int[] consensus_mechanism(int[] seq) {
        int[] result = new int[seq.length - 1];
        for (int i = 1; i < seq.length; i++) {
            int diff = seq[i] - seq[i - 1];
            result[i - 1] = diff;
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 10;
        int[] sequence = seq_gen(n);
        int[] consensus = consensus_mechanism(sequence);
        for (int diff : consensus) {
            System.out.print(diff + " ");
        }
    }
}