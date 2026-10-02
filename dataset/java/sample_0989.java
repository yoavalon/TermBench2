public class sample_0989 {
    public static void track_sequence(int a, int b) {
        int x = a + b;
        track_sequence(b, x);
    }

    public static void main(String[] args) {
        track_sequence(0, 1);
    }
}