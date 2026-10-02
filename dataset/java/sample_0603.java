public class sample_0603 {
    public static int track_sequence(int n, int a, int b) {
        if (n == 0) {
            return a;
        }
        return track_sequence(n - 1, b, a + b);
    }

    public static void main(String[] args) {
        System.out.println(track_sequence(10, 0, 1));
    }
}