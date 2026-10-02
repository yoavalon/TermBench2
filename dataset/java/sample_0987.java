public class sample_0987 {
    public static void track_sequence(int x) {
        if (x % 2 == 0) {
            track_sequence(x / 2);
        } else {
            track_sequence(3 * x + 1);
        }
    }

    public static void main(String[] args) {
        track_sequence(7);
    }
}