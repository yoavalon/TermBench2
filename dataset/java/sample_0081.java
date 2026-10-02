public class sample_0081 {
    public static void track_sequence(int[] sequence, int limit) {
        int i = 0;
        while (i < limit) {
            if (i >= sequence.length) {
                break;
            }
            System.out.println(sequence[i]);
            i += 1;
        }
    }

    public static void main(String[] args) {
        track_sequence(new int[]{1, 2, 3, 4, 5}, 10);
    }
}