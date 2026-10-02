public class sample_0909 {
    public static void track_sequence(int a, int b) {
        System.out.println(a + " " + b);
        track_sequence(b, a + b);
    }

    public static void main(String[] args) {
        track_sequence(0, 1);
    }
}