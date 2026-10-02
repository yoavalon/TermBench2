public class sample_2580 {
    public static int[] generate_sequence(int n) {
        int[] sequence = new int[n];
        sequence[0] = 0;
        sequence[1] = 1;
        for (int i = 2; i < n; i++) {
            sequence[i] = sequence[i - 1] + sequence[i - 2];
        }
        return sequence;
    }

    public static boolean validate_sequence(int[] seq, int target) {
        for (int value : seq) {
            if (value == target) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int n = 10;
        int[] sequence = generate_sequence(n);
        int target = 5;
        boolean result = validate_sequence(sequence, target);
        System.out.println(result);
    }
}