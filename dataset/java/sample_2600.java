public class sample_2600 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        for (int i = 1; i <= n; i++) {
            sequence[i - 1] = i * (i + 1) / 2;
        }
        return sequence;
    }

    public static int[] optimize_inventory(int[] seq, int target) {
        for (int i = 0; i < seq.length; i++) {
            if (seq[i] >= target) {
                return new int[]{i, seq[i]};
            }
        }
        return new int[]{};
    }

    public static void main(String[] args) {
        int n = 10;
        int target = 20;
        int[] seq = generate_sequence(n);
        int[] result = optimize_inventory(seq, target);
        if (result.length > 0) {
            System.out.println("Optimal index: " + result[0] + ", Value: " + result[1]);
        } else {
            System.out.println("Target not met.");
        }
    }
}