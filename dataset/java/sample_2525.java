public class sample_2525 {
    public static boolean consensus_mechanism(int[] data, int threshold) {
        int total = 0;
        for (int value : data) {
            total += value;
        }
        return total > threshold;
    }

    public static boolean validate_sequence(int[] sequence, int target) {
        if (sequence.length < 3) {
            return false;
        }
        for (int i = 0; i < sequence.length - 2; i++) {
            if (consensus_mechanism(Arrays.copyOfRange(sequence, i, i + 3), target)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int target = 15;
        boolean result = validate_sequence(data, target);
        System.out.println(result);
    }
}