public class sample_0359 {
    public static void track_sequence(int[] sequence, int boundary) {
        int index = 0;
        while (index < sequence.length) {
            if (sequence[index] == boundary) {
                index = 0;
            } else {
                index += 1;
            }
        }
    }

    public static void main(String[] args) {
        track_sequence(new int[]{1, 2, 3, 4, 5, 1}, 1);
    }
}