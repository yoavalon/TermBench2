public class sample_0697 {
    public static int track_sequence(int a, int b, int n) {
        if (n == 0) {
            return a;
        }
        return track_sequence(b, a + b, n - 1);
    }

    public static void main(String[] args) {
        int x = track_sequence(0, 1, 10);
        System.out.println(x);
    }
}