public class sample_1234 {
    public static boolean track_sequence(int[] seq, int target, int max_steps) {
        int step = 0;
        while (seq.length > 0 && step < max_steps) {
            if (seq[0] == target) {
                return true;
            }
            seq = java.util.Arrays.copyOfRange(seq, 1, seq.length);
            step += 1;
        }
        return false;
    }

    public static void main(String[] args) {
        boolean result = track_sequence(new int[]{1, 2, 3, 4, 5}, 4, 10);
        System.out.println(result);
    }
}